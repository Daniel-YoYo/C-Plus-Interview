#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main( int argc, char *argv[] )
{
    if( argv[1] == NULL )
    {
        perror("Command error");
        return -1;
    }

    int ch,tmpFd;
    int fFlag = O_RDWR | O_EXCL;
    int fd = open( argv[1], fFlag );
    if( fd < 0 )
    {
        perror("Open File Error");
        return -1;
    }

    //将文件的描述符拷贝到0(标准输入)
    tmpFd = dup( 0 );
    dup2(fd, 0);

    while ( ( ch = getchar() ) != EOF )
    {
        putchar( ch );
    }
    printf("\n");

    dup2( tmpFd, 0 );

    close( fd );

    return 0;
}