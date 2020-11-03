/*
 * @Author: your name
 * @Date: 2020-06-08 13:53:05
 * @LastEditTime: 2020-06-08 14:31:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Unix-C/pthread/pthread_join.cpp
 */  

// 线程的汇合,获取线程退出状态码
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void printTids( const char *s )
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf( "%s Pid:%lu Tid:%lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid );
}

void *thread_fun1( void *arg )
{
    printTids( "thread_fun1 returning\n");
    sleep(1);
    return ((void *)1);
}

void *thread_fun2( void *arg )
{
    printTids( "thread_fun1 exiting\n");
    pthread_exit( ((void *)2) );
}

int main( void )
{
    pthread_t tid1, tid2;
    void *rval_ptr = NULL;
    int err = pthread_create( &tid1, NULL, thread_fun1, NULL );
    if( err != 0 )
    {
        perror("pthread_create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &tid2, NULL, thread_fun2, NULL );
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