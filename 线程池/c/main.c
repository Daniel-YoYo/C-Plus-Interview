/*
 * @Author: your name
 * @Date: 2020-05-17 14:28:17
 * @LastEditTime: 2020-08-02 15:36:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/线程池/c/main.c
 */ 
#include "threadpool.h"

void* do_work( void* p )
{
    printf("%d\t do_work tid:%ld\n", (int *)p,pthread_self() );
}

int main(void)
{   
    int p = 123456;

    threadpool_t *thp = threadpool_create(10, 100, 100);
    printf("threadpool init ... ... \n");
   threadpool_add_task(thp, do_work, (void *)p );
   threadpool_destroy(thp);

    return 0;
}