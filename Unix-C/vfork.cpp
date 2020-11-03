/*
 * @Author: your name
 * @Date: 2020-06-02 16:37:05
 * @LastEditTime: 2020-06-02 17:23:25
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
    
    if( ( pid = vfork() ) < 0 )
    {
        perror("fork");
        exit( EXIT_FAILURE );
    }
    else if ( pid == 0 )
    {
        // 子进程创建时,不将父进程的地址空间完全复制到子进程中,因为子进程会立刻执行exec函数
        // 所以也不会引用父进程的地址空间
        // 但是子进程在调用exec和exit之前,他在父进程的空间中运行,所以子进程修改数据会更新到父进程
        globvar++;
        var++;
        // 子进程结束后,一定要调用exit函数,父进程才被调用,结束之前,内核会使父进程处于休眠状态
        exit( EXIT_SUCCESS );
    }
    
    // 子进程修改的数据会更新到父进程
    printf("Pid:%ld, glob=%d, var=%d\n", (long)getpid(), globvar, var );

    exit( EXIT_SUCCESS );
}
