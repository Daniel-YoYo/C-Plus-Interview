/**
 *  孤儿进程: 父进程先于子进程结束,那么该父进程的所有子进程都过继给１号进程,
 *  这样的进程称为"孤儿进程”
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if( pid == -1 )
    {
        perror("fork");
        return -1;
    }

    if( pid == 0 )
    {
        printf("childPid:%ld\n", getpid() );
        sleep(3);
        printf("ParentPid:%ld\n", getppid() );
    }
    else
    {
        printf("ParentPid:%ld\n", getpid() );
        sleep(1);
    }

    return 0;
}