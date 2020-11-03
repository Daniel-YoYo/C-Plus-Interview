#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();
    if( pid == -1 )
    {
        perror("fork");
        return -1;
    }

    if( pid == 0 )
    {
        // 子进程执行代码
        printf("This is childProcess!\n");
    }
    else
    {
        printf("This is ParentProcess!\n");
    }

    return 0;
}