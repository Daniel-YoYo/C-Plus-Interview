#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main( int argc, char *argv[] )
{
    // 文件操作权限
    int fFlag = O_RDWR | O_CREAT;
    // 新文件权限
    mode_t fMode = 0664;

    int fd = open( argv[1], fFlag, fMode );
    if( fd == -1 )
    {
        perror("file open error");
        return -1;
    }

    void *p = mmap( NULL, 1024, PROT_READ, MAP_SHARED, 0);
    if( p == NULL )
    {
        perror("mmap file error");
        close( fd );
        return -1;
    }

    close( fd );

    printf("Open File Success!\n");

    return 0;
}