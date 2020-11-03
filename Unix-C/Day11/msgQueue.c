/**
 *  消息队列实现进程间通信
 *  步骤：
 *  1、 ftok(3)申请一个key值
 *  2、 使用　msgget(2)、msgsnd(2)、msgrcv(2) 操作消息队列
 *  3、 在使用共享内存时需要对临界数据进行加锁操作,进程同步
 * 　
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

// 定义传递消息结构体
typedef struct msgBuf
{
    long msgType;
    char mtext[128];
}msg_t;


int main()
{
    key_t key;

    //　消息缓存区
    msg_t msgbuf;
    msgbuf.msgType = 3;
    strcpy( msgbuf.mtext, "Message Queue\n" );

    msg_t msgbuf1;
    msgbuf1.msgType = 4;
    strcpy( msgbuf1.mtext, "Message Queue1\n" );

    key = ftok( ".", 31 );
    if( key == -1 )
    {
        perror("ftok");
        return -1;
    }

    printf("key:%d\n", key );

    // 使用msgget(2)根据键值创建消息队列并设置权限
    int msgId = msgget( key, IPC_CREAT | 0644 );
    if( msgId == -1 )
    {
        perror("msgget");
        return -1;
    }
    
    printf("msgId:%d\n", msgId );

    // 使用msgsnd(2) 往消息队列中发送数据
    int result = msgsnd( msgId, &msgbuf, strlen( msgbuf.mtext ), 0 );
    if( result == -1 )
    {
        perror("msgsnd");
        return -1;
    }

    int result1 = msgsnd( msgId, &msgbuf1, strlen( msgbuf1.mtext ), 0 );
    if( result1 == -1 )
    {
        perror("msgsnd");
        return -1;
    }

    printf( "Message send success!\n" );

    return 0;
}

