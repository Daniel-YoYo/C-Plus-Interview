/**
 * 使用 pid_t wait(int *status); 阻塞等待回收子进程资源
 * 
 * */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t cpid, w;
    int status;

    cpid = fork();
    if (cpid == -1) 
    {
        perror("fork");
        // 异常退出
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {            /* Code executed by child */
        printf("Child PID is %ld\n", (long) getpid());
        if (argc == 1)
        {
            pause();                    /* Wait for signals */
        }
        // 
        _exit(atoi(argv[1]));
    } 
    else 
    {     
        // 阻塞等待所有子进程结束,回收子进程资源
        w = wait( &status );
        if (w == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) 
        {
            printf("exited, status=%d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("killed by signal %d\n", WTERMSIG(status));
        } 
        else if (WIFSTOPPED(status)) 
        {
            printf("stopped by signal %d\n", WSTOPSIG(status));
        } 
        else if (WIFCONTINUED(status)) 
        {
            printf("continued\n");
        }

        exit(EXIT_SUCCESS);
    }
}