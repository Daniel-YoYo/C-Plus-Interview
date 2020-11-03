/**
 *  为系统信号注册处理程序
 * 
 * */

#include <signal.h>
#include <stdio.h>

// 信号处理函数类型
typedef void (*sighandler_t)(int);

void fun( int signalNumIn )
{
    printf("My Signal %d\n", signalNumIn );
}

int main()
{
    // 对２号信号忽略处理
    // signal( SIGINT, SIG_IGN );

    // 注册自定义信号处理函数
    signal( SIGINT, fun );

    getchar();

    return 0;
}