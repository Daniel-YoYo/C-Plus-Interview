#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fun1()
{
    printf("fun1.....\n");
}

void fun2()
{
    printf("fun2.....\n");
}

int main()
{
    // 父进程注册遗言函数
    // 同一个函数可以多次注册
    // 遗言函数的执行顺序是　先注册的后执行,类似栈
    atexit( fun1 );
    atexit( fun2 );
    atexit( fun2 );

    pid_t pid = fork();
    if( pid == -1 )
    {
        perror("fork");
        return -1;
    }

    if( pid == 0 )
    {
        // 子进程继承父进程的遗言函数
    }
    else
    {
        getchar();
    }

    return 0;
}