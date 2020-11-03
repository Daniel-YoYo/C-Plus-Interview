/**
 *  共享内存实现进程间通信
 *  步骤：
 *  1、 ftok(3)申请一个key值
 *  2、 使用　shmget(2)、shmat(2)、shmdt(2)申请共享内存
 *  3、 在使用共享内存时需要对临界数据进行加锁操作,进程同步
 * 　
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    key_t key;

    key = ftok( ".", 31 );
    if( key == -1 )
    {
        perror("ftok");
        exit( EXIT_FAILURE );
    }

    printf("key:%d\n", key );

    // 申请共享内存
    int shmId = shmget( key, 1024, IPC_CREAT | 0644 );
    if( shmId == -1 )
    {
        perror( "shmget" );
        return -1;
    }

    // 将共享内存段以可读可写权限与当前进程绑定
    void *shmAddr = shmat( shmId, NULL, 0 );
    if( shmAddr == (void *)-1)
    {
        perror("shmat");
        return -1;
    }

    strcpy( shmAddr, "Hello shared mermory" );

    getchar();

    shmdt( shmAddr );
    
    return 0;
}

