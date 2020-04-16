#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main( int argc, char *argv[] )
{
    if( argv[1] == NULL )
    {
        printf("Command Error!\n");
        return -1;
    }

    char buffer[1024];

    int fFlag = O_RDONLY | O_EXCL;

    int fd = open( argv[1], fFlag );
    if( fd == -1 )
    {
        perror("file open error");
        return -1;
    }

    int r = 0;

    while( ( r = read( fd, buffer, 1024 ) ) > 0  )
    {
        write( 1, buffer, r );
    }

    printf("\n");
    
    return 0;
}