/*
 * @Author: your name
 * @Date: 2020-05-17 13:55:56
 * @LastEditTime: 2020-08-02 15:29:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/线程池/C++/main.cpp
 */ 

#include <iostream>
#include "threadpool.h"

using namespace std;

void *do_work( void *p )
{
    printf("-------- do_work tid: 0x%x.....%d \n", (unsigned int)pthread_self(), static_cast< int* >( p ) );
}

int main(void)
{   
    /* 线程池初始化，其管理者线程及工作线程都会启动 */
    ThreadPool threadPool;
    threadPool.threadpool_create( 10, 100, 100 );
    printf("threadpool init ... ... \n");

    /* 接收到任务后添加 */
    for (int i = 0; i < 100; i++)
    {
        threadPool.threadpool_add_task( do_work, (void *)i );
    }
    
    threadPool.threadpool_destroy();

    return 0;
}