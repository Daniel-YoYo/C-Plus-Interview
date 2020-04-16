#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int *p = (int *)malloc( sizeof(int) );

    printf("PID:%d\n", getpid() );
    printf("%p\t%d\n", p,sizeof(p) );

    *p = 123;

    getchar();

    free( p );

    return 0;
}