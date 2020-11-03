/*
 * @Author: your name
 * @Date: 2020-06-08 14:31:46
 * @LastEditTime: 2020-06-08 14:48:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Unix-C/pthread/pthread_cleanup_push.cpp
 */ 
// 为线程注册线程清理处理程序
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// 线程清理处理函数
void cleanup( void *arg )
{
    printf("Cleanup:%s\n", (char *)arg );
}

void *thread_fun1( void *arg )
{
    printf("thread 1 start\n");

    // 注册线程清理处理程序
    pthread_cleanup_push( cleanup, "thread 1 first handler" );
    pthread_cleanup_push( cleanup, "thread 1 second handler");

    printf( "thread 1 push complete\n" );

    if( arg )
    {
        // 线程１例程是返回退出,线程清理处理程序不会被调用
        return ((void *)1);
    }

    // 出栈,执行线程清理处理程序
    pthread_cleanup_pop( 0 );
    pthread_cleanup_pop( 0 );

    return ((void *)1);
}

void *thread_fun2( void *arg )
{
    printf("thread 2 start\n");

    pthread_cleanup_push( cleanup, "thread 2 first handler");
    pthread_cleanup_push( cleanup, "thread 2 second handler");

    printf( "thread 2 push complete\n" );

    if( arg )
    {
        // 退出线程,执行线程清理处理程序
        pthread_exit( ((void *)2) );
    }

    pthread_cleanup_pop( 0 );
    pthread_cleanup_pop( 0 );

    pthread_exit( ((void *)2) );
}

int main( void )
{
    pthread_t tid1, tid2;
    void *rval_ptr = NULL;
    int err = pthread_create( &tid1, NULL, thread_fun1, (void *)1 );
    if( err != 0 )
    {
        perror("pthread_create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &tid2, NULL, thread_fun2, (void *)2 );
    if( err != 0 )
    {
        perror("pthread_create");
        exit( EXIT_FAILURE );
    }

    err = pthread_join( tid1, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 1");
        exit( EXIT_FAILURE );
    }
    printf( "thread 1 exit code :%d\n", (long)rval_ptr );

    err = pthread_join( tid2, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 2");
        exit( EXIT_FAILURE );
    }
    printf( "thread 2 exit code :%d\n", (long)rval_ptr );

    exit( EXIT_SUCCESS );
}