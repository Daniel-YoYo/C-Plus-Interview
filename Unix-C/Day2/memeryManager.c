#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    const int num = 100;
    int *p = &num;
    *p = 120;
    printf("%d\n", *p );
    char *str = "Hello Memery Manager!";
    pid_t pid = getpid();
    printf("Process PID:%d\n", pid );
    printf("&str :%p\n", &str );
    printf("str :%p\n", str );
    getchar();
    return 0;
}
