/*
 * @Author: your name
 * @Date: 2020-06-08 17:39:06
 * @LastEditTime: 2020-06-08 18:45:45
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Unix-C/pthread_mutex.c
 */ 
// 使用两个互斥量,以相同的顺序加锁,避免死锁
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define NHASH 29
#define HASH(id)    (((unsigned long)id)%NHASH)

struct foo *fh[ NHASH ];

pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

struct foo
{
    int f_count;
    pthread_mutex_t f_lock;
    int f_id;

    struct foo *f_next;

    int data;
};

// 分配对象
struct  foo *foo_alloc( int id )
{
    struct foo *fp;

    int idx;

    if( ( fp = malloc( sizeof( struct foo) )) != NULL  )
    {
        fp->f_count = 1;
        fp->f_id = id;
        fp->data = 0;
        if( pthread_mutex_init( &fp->f_lock, NULL ) != 0 )
        {
            free( fp );
            return NULL;
        } 

        idx = HASH( id );

        pthread_mutex_lock( &fp->f_lock );

        fp->f_next = fh[ idx ];
        fh[ idx ] = fp;

        pthread_mutex_lock( &fp->f_lock );
        pthread_mutex_unlock( &hashlock );
        // 终端初始化
        pthread_mutex_unlock( &fp->f_lock );
    }

    return fp;    
}

// 添加对象的引用
void foo_hold( struct foo *fp )
{
    if( fp == NULL )
    {
        perror("foo_hold object is null!");
        return;
    }

    pthread_mutex_lock( &fp->f_lock );
    fp->f_count++;
    pthread_mutex_unlock( &fp->f_lock );
}

// 释放引用对象
void foo_rele( struct foo *fp )
{
    struct foo *tfp;
    int idx;

    pthread_mutex_lock( &fp->f_lock );

    if( fp->f_count == 1 )
    {
        pthread_mutex_unlock( &fp->f_lock );
        pthread_mutex_lock( &hashlock );
        pthread_mutex_lock( &fp->f_lock );

        // 需要重新检查条件
        if( fp->f_count != 1 )
        {
            fp->f_count--;
            pthread_mutex_unlock( &fp->f_lock );
            pthread_mutex_unlock( &hashlock );
            return;
        }

        //从清单中删除
        idx = HASH( fp->f_id );
        tfp = fh[ idx ];
        if( tfp == fp )
        {
            fh[ idx ] = fp->f_next;
        }
        else
        {
            while ( tfp->f_next != fp )
            {
                tfp = tfp->f_next;
            }
            
            tfp->f_next = fp->f_next;
        }

        pthread_mutex_unlock( &hashlock );
        pthread_mutex_unlock( &fp->f_lock );
        pthread_mutex_destroy( &fp->f_lock );
        free( fp );
        
    }
    else
    {
        fp->f_count--;
        pthread_mutex_unlock( &fp->f_lock );
    } 
}

struct foo *foo_find( int id )
{
    struct foo *fp;

    pthread_mutex_lock( &hashlock );
    for (fp = fh[ HASH(id) ]; fp != NULL; fp = fp->f_next )
    {
        if( fp->f_id == id )
        {
            foo_hold( fp );
            break;
        }
    }

    pthread_mutex_unlock( &hashlock );

    return fp;
}

void *thread_fun1( void *arg )
{
    struct foo *tp = (struct foo *)arg;
    printf( "start thread 1\n" );
    foo_hold( tp );
    tp->data+=1;
    foo_rele( tp );

    pthread_exit( (void *)&tp->data );
}

void *thread_fun2( void *arg )
{
    struct foo *tp = (struct foo *)arg;
    printf( "start thread 2\n" );
    foo_hold( tp );
    tp->data+=1;
    foo_rele( tp );

    pthread_exit( (void *)&tp->data );
}

void *thread_fun3( void *arg )
{
    struct foo *tp = (struct foo *)arg;
    printf( "start thread 3\n" );
    foo_hold( tp );
    tp->data+=1;
    foo_rele( tp );

    pthread_exit( (void *)&tp->data );
}

void *thread_fun4( void *arg )
{
    struct foo *tp = (struct foo *)arg;
    printf( "start thread 4\n" );
    foo_hold( tp );
    tp->data+=1;
    foo_rele( tp );

    pthread_exit( (void *)&tp->data );
}

void *thread_fun5( void *arg )
{
    struct foo *tp = (struct foo *)arg;
    printf( "start thread 5\n" );
    foo_hold( tp );
    tp->data+=1;
    foo_rele( tp );

    pthread_exit( (void *)&tp->data );
}


int main( void )
{
    struct  foo *fp = NULL;
    fp = foo_alloc( 10 );

    pthread_t t1,t2,t3,t4,t5;
   
    void *rval_ptr = NULL;
    int err = pthread_create( &t1, NULL, thread_fun1, ( void * )fp );
    if( err != 0 )
    {
        perror("pthread 1 create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &t2, NULL, thread_fun2, ( void * )fp );
    if( err != 0 )
    {
        perror("pthread 2 create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &t3, NULL, thread_fun3, ( void * )fp );
    if( err != 0 )
    {
        perror("pthread 3 create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &t4, NULL, thread_fun4, ( void * )fp );
    if( err != 0 )
    {
        perror("pthread 4 create");
        exit( EXIT_FAILURE );
    }

    err = pthread_create( &t5, NULL, thread_fun5, ( void * )fp );
    if( err != 0 )
    {
        perror("pthread 5 create");
        exit( EXIT_FAILURE );
    }

    err = pthread_join( t1, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 1");
        exit( EXIT_FAILURE );
    }
    printf( "thread 1 exit code :%d\n", (long)rval_ptr );

    err = pthread_join( t2, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 2");
        exit( EXIT_FAILURE );
    }
    printf( "thread 2 exit code :%d\n", (long)rval_ptr );

        err = pthread_join( t3, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 3");
        exit( EXIT_FAILURE );
    }
    printf( "thread 3 exit code :%d\n", (long)rval_ptr );

    err = pthread_join( t4, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 4");
        exit( EXIT_FAILURE );
    }
    printf( "thread 4 exit code :%d\n", (long)rval_ptr );

    err = pthread_join( t5, &rval_ptr );
    if( err != 0 )
    {
        perror("pthread_join: can't join with thread 5");
        exit( EXIT_FAILURE );
    }
    printf( "thread 5 exit code :%d\n", (long)rval_ptr );

    sleep(2);
    
    exit( EXIT_SUCCESS );
}