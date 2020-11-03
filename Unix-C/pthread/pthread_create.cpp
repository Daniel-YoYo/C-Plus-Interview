/*
 * @Author: your name
 * @Date: 2020-06-08 13:15:41
 * @LastEditTime: 2020-06-08 13:27:10
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Editfasfas
 * @FilePath: /C++/Unix-C/pthread/pthread_create.cpp
 */ 
#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

pthread_t ntid;

void printTids( const char *s )
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf( "%s Pid:%lu Tid:%lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid );
}

void *thread_fun( void *arg )
{
    printTids( "New thread:");
    return ((void *)0);
}

int main( void )
{
    int err = pthread_create( &ntid, NULL, thread_fun, NULL );
    if( err != 0 )
    {
        perror("pthread_create");
        exit( EXIT_FAILURE );
    }

    printTids( "Main thread:");

    sleep(1);

    exit( EXIT_SUCCESS );
}