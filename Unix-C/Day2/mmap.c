#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int main( void )
{
    int prot = PROT_READ | PROT_WRITE;
    int flag = MAP_PRIVATE | MAP_ANONYMOUS;

    // 采用匿名映射,不需要打开文件
    void *addr = mmap( NULL, 1024, prot, flag, -1, 0 );

    if( addr == MAP_FAILED )
    {
        perror("mmap error");
        return -1;
    }

    printf("mmap Success!\n");

    strcpy( addr, "Hello mmap!" );

    printf("%s\n", (char *)addr );

    munmap(addr, 1024);

    return 0;
}

