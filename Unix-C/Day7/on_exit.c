/***
 *  带参数的遗言函数 int on_exit(void (*function)(int , void *), void *arg);
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fun1( int n, void *arg )
{
    printf("fun1.....%d\t%s\n", n, (char *)arg );
}

int main()
{
    // 父进程注册遗言函数
    // 同一个函数可以多次注册
    // 遗言函数的执行顺序是　先注册的后执行,类似栈
    on_exit( fun1, "1" );
    on_exit( fun1, "2" );
    on_exit( fun1, "3" );

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