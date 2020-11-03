#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int pPid[2];
    int cPid;
    char buf[128];
    char *msg = "Hello Pipe!";

    // 创建无名管道,用于父子进程通信
    int resValue = pipe( pPid );
    if( resValue == -1 )
    {
        perror("pipe");
        exit( EXIT_FAILURE );
    }

    cPid = fork();
    if( cPid < 0 )
    {
        perror("fork");
        exit( EXIT_FAILURE );
    }

    if( cPid == 0 )
    {
        // 子进程读取父进程发送的数据,显示到显示器
        close( pPid[1] );
        int rt = read( pPid[0], buf, sizeof( buf ));
        if( rt > 0 )
        {
            printf("ChildPid:%d\tRead :%s\n", getpid(), buf );
            exit( EXIT_SUCCESS );
        }
    }
    else
    {
        // 关闭管道读端,向写端写数据,传给子进程,并阻塞等待子进程结束
        close( pPid[0] );
        write( pPid[1], msg, strlen( msg ) );
        wait( NULL );
    }

    return 0;
}

