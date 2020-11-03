/*
 * @Author: your name
 * @Date: 2020-05-17 11:25:26
 * @LastEditTime: 2020-08-02 15:34:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/8.C语言线程池/threadpool.c
 */ 
#include "threadpool.h"

using namespace std;

threadpool_t * ThreadPool::pool = nullptr;

ThreadPool::ThreadPool()
{

}


ThreadPool::~ThreadPool()
{
   if( pool != NULL )
   {
      threadpool_free();
   }
}


/**
 * @description: 
 * @param {type} 
 * @return: 
 */
bool ThreadPool::threadpool_create( int min_thr_num, int max_thr_num, int queue_max_size )
{
   int i;
   pool = NULL;
   do
   {
      if ((pool=(threadpool_t *)malloc(sizeof(threadpool_t))) == NULL)
      {
        printf("malloc threadpool false; \n");
	      break;   
      }
      /*信息初始化*/
      pool->min_thr_num = min_thr_num;
      pool->max_thr_num = max_thr_num;
      pool->busy_thr_num = 0;
      pool->live_thr_num = min_thr_num;
      pool->wait_exit_thr_num = 0;
      pool->queue_front = 0;
      pool->queue_rear = 0;
      pool->queue_size = 0;
      pool->queue_max_size = queue_max_size;
      pool->shutdown = false;
   
      /*根据最大线程数，给工作线程数组开空间，清0*/
      pool->threads = (pthread_t *)malloc(sizeof(pthread_t)*max_thr_num);
      if (pool->threads == NULL)
      {
         printf("malloc threads false;\n");
	      break;
      }
      memset(pool->threads, 0, sizeof(pthread_t)*max_thr_num);

      /*队列开空间*/
      pool->task_queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t)*queue_max_size);
      if (pool->task_queue == NULL)
      {
         printf("malloc task queue false;\n");
	      break;
      }

      /*初始化互斥锁和条件变量*/
      if (  pthread_mutex_init(&(pool->lock), NULL) != 0           ||
            pthread_mutex_init(&(pool->thread_counter), NULL) !=0  || 
	         pthread_cond_init(&(pool->queue_not_empty), NULL) !=0  ||
	         pthread_cond_init(&(pool->queue_not_full), NULL) !=0  )
      {
         printf("init lock or cond false;\n");
         break;
      }

      /*启动min_thr_num个工作线程*/
      for (i=0; i<min_thr_num; i++)
      {
         /*pool指向当前线程池*/
         pthread_create(&(pool->threads[i]), NULL, threadpool_thread, (void*)this );
	      printf("start thread 0x%x... \n", (unsigned int)pool->threads[i]);
      }
      /*管理者线程*/
      pthread_create(&(pool->admin_tid), NULL, admin_thread, (void*)this );

      return true;

   } while(0);

   /*释放pool的空间*/
   threadpool_free();

   return false;
}

/*释放线程池*/
int ThreadPool::threadpool_free()
{
   if (pool == NULL)
   {
     return -1;
   }

   if (pool->task_queue)
   {
      free(pool->task_queue);
   }
   if (pool->threads)
   {
      free(pool->threads);
      pthread_mutex_lock(&(pool->lock));               /*先锁住再销毁*/
      pthread_mutex_destroy(&(pool->lock));
      pthread_mutex_lock(&(pool->thread_counter));
      pthread_mutex_destroy(&(pool->thread_counter));
      pthread_cond_destroy(&(pool->queue_not_empty));
      pthread_cond_destroy(&(pool->queue_not_full));
   }
   free(pool);
   pool = NULL;

   return 0;
}

/*销毁线程池*/
int ThreadPool::threadpool_destroy()
{
   int i;
   if (pool == NULL)
   {
     return -1;
   }
   pool->shutdown = true;

   /*销毁管理者线程*/
   pthread_join(pool->admin_tid, NULL);

   //通知所有线程去自杀(在自己领任务的过程中)
   for (i=0; i<pool->live_thr_num; i++)
   {
     pthread_cond_broadcast(&(pool->queue_not_empty));
   }

   /*等待线程结束 先是pthread_exit 然后等待其结束*/
   for (i=0; i<pool->live_thr_num; i++)
   {
     pthread_join(pool->threads[i], NULL);
   }

   threadpool_free();
   return 0;
}

/*管理线程*/
void * ThreadPool::admin_thread( void *pThis )
{
   int i;
   while (!pool->shutdown)
   {
      printf("admin -----------------\n");
      sleep(DEFAULT_TIME);                             /*隔一段时间再管理*/
      pthread_mutex_lock(&(pool->lock));               /*加锁*/ 
      int queue_size = pool->queue_size;               /*任务数*/
      int live_thr_num = pool->live_thr_num;           /*存活的线程数*/
      pthread_mutex_unlock(&(pool->lock));             /*解锁*/
      
      pthread_mutex_lock(&(pool->thread_counter));
      int busy_thr_num = pool->busy_thr_num;           /*忙线程数*/  
      pthread_mutex_unlock(&(pool->thread_counter));

      printf("admin busy live -%d--%d-\n", busy_thr_num, live_thr_num);
      /*创建新线程 实际任务数量大于 最小正在等待的任务数量，存活线程数小于最大线程数*/
      if (queue_size >= MIN_WAIT_TASK_NUM && live_thr_num <= pool->max_thr_num)
      {
         printf("admin add-----------\n");
         pthread_mutex_lock(&(pool->lock));
         int add=0;

         /*一次增加 DEFAULT_THREAD_NUM 个线程*/
	      for (i=0; i<pool->max_thr_num && add<DEFAULT_THREAD_NUM 
	            && pool->live_thr_num < pool->max_thr_num; i++)
	      {
	         if (pool->threads[i] == 0 || !is_thread_alive(pool->threads[i]) )
	         {
	            pthread_create(&(pool->threads[i]), NULL, threadpool_thread, NULL );
	            add++;
	            pool->live_thr_num++;
	            printf("new thread -----------------------\n");
	         }
	      }

	      pthread_mutex_unlock(&(pool->lock));
      }

      /*销毁多余的线程 忙线程x2 都小于 存活线程，并且存活的大于最小线程数*/
      if ((busy_thr_num*2) < live_thr_num  &&  live_thr_num > pool->min_thr_num)
      {
        // printf("admin busy --%d--%d----\n", busy_thr_num, live_thr_num);
         /*一次销毁DEFAULT_THREAD_NUM个线程*/
	      pthread_mutex_lock(&(pool->lock));
         pool->wait_exit_thr_num = DEFAULT_THREAD_NUM;
	      pthread_mutex_unlock(&(pool->lock));

	      for (i=0; i<DEFAULT_THREAD_NUM; i++)
	      {
	         //通知正在处于空闲的线程，自杀
	         pthread_cond_signal(&(pool->queue_not_empty));
	         printf("admin cler --\n");
	      }
      }
   }
  
   return NULL;
}

/*线程是否存活*/
int ThreadPool::is_thread_alive(pthread_t tid)
{
   int kill_rc = pthread_kill(tid, 0);     //发送0号信号，测试是否存活
   if (kill_rc == ESRCH)  //线程不存在
   {
      return false;
   }
   return true;
}

/*工作线程*/
void * ThreadPool::threadpool_thread( void *pThis )
{
   cout << "Working Thread......" << endl;
   // 临时变量,接收当前工作线程
   threadpool_task_t task;

   while (true)
   {
      pthread_mutex_lock(&(pool->lock));

      //无任务则阻塞在 任务队列不为空 上，有任务则跳出
      while ((pool->queue_size == 0) && (!pool->shutdown))
      { 
         printf("thread 0x%x is waiting \n", (unsigned int)pthread_self());
         pthread_cond_wait(&(pool->queue_not_empty), &(pool->lock));

         //判断是否需要清除线程,自杀功能
         if (pool->wait_exit_thr_num > 0)
         {
            pool->wait_exit_thr_num--;
            //判断线程池中的线程数是否大于最小线程数，是则结束当前线程
	         if (pool->live_thr_num > pool->min_thr_num)
	         {
	            printf("thread 0x%x is exiting \n", (unsigned int)pthread_self());
	            pool->live_thr_num--;
	            pthread_mutex_unlock(&(pool->lock));
	            pthread_exit(NULL);//结束线程
	         }
         }
      }

      //线程池开关状态
      if (pool->shutdown) //关闭线程池
      {
         pthread_mutex_unlock(&(pool->lock));
         printf("thread 0x%x is exiting \n", (unsigned int)pthread_self());
         pthread_exit(NULL); //线程自己结束自己
      }

      //否则该线程可以拿出任务
      task.function = pool->task_queue[pool->queue_front].function; //出队操作
      task.arg = pool->task_queue[pool->queue_front].arg;

      //环型结构
      pool->queue_front = (pool->queue_front + 1) % pool->queue_max_size;
      pool->queue_size--;

      //通知可以添加新任务
      pthread_cond_broadcast(&(pool->queue_not_full));
    
      //释放线程锁
      pthread_mutex_unlock(&(pool->lock));
    
      //执行刚才取出的任务
      printf("thread 0x%x start working \n", (unsigned int)pthread_self());
      //锁住忙线程变量
      pthread_mutex_lock(&(pool->thread_counter));            
      pool->busy_thr_num++;
      pthread_mutex_unlock(&(pool->thread_counter));

      //执行任务
      (*(task.function))(task.arg);                           

      //任务结束处理
      printf("thread 0x%x end working \n", (unsigned int)pthread_self());
      pthread_mutex_lock(&(pool->thread_counter));
      pool->busy_thr_num--;
      pthread_mutex_unlock(&(pool->thread_counter));
  }

   // 当前工作线程退出
   pthread_exit(NULL);
}

/*向线程池的任务队列中添加一个任务*/
int ThreadPool::threadpool_add_task( void *(*function)(void *arg), void *arg )
{
   pthread_mutex_lock(&(pool->lock));

   /*如果队列满了,调用wait阻塞*/
   while ((pool->queue_size == pool->queue_max_size) && (!pool->shutdown))
   {
      pthread_cond_wait(&(pool->queue_not_full), &(pool->lock));
   }
   /*如果线程池处于关闭状态*/
   if (pool->shutdown)
   {
      pthread_mutex_unlock(&(pool->lock));
      return -1;
   }

   /*清空工作线程的回调函数的参数arg*/
   if (pool->task_queue[pool->queue_rear].arg != NULL)
   {
      free(pool->task_queue[pool->queue_rear].arg);
      pool->task_queue[pool->queue_rear].arg = NULL;
   }
   
   /*添加任务到任务队列*/
   pool->task_queue[pool->queue_rear].function = function;
   pool->task_queue[pool->queue_rear].arg = arg;
   /* 逻辑环  */
   pool->queue_rear = (pool->queue_rear + 1) % pool->queue_max_size;
   pool->queue_size++;

   /*添加完任务后,队列就不为空了,唤醒线程池中的一个线程*/
   pthread_cond_signal(&(pool->queue_not_empty));
   pthread_mutex_unlock(&(pool->lock));

   return 0;
}

