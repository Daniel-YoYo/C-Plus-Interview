/*
 * @Author: your name
 * @Date: 2020-06-02 16:37:05
 * @LastEditTime: 2020-06-02 17:05:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/Unix-C/fork.cpp
 */ 
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
    int var = 88;
    pid_t pid;

    if( write( STDOUT_FILENO, buf, sizeof( buf ) - 1) != sizeof( buf) -1 )
    {
        perror( "write ");
    }

    cout << "Start fork" << endl;
    
    if( ( pid = fork() ) < 0 )
    {
        perror("fork");
        exit( EXIT_FAILURE );
    }
    else if ( pid == 0 )
    {
        globvar++;
        var++;
    }
    else
    {
        sleep( 2 );
    }
    
    // 父子进程,写时复制技术,造成父子进程输出值不一样
    // 子进程共享父进程数据段、栈、堆;当有修改时内核为修改区域复制一个副本
    printf("Pid:%ld, glob=%d, var=%d\n", (long)getpid(), globvar, var );

    exit( EXIT_SUCCESS );
}
