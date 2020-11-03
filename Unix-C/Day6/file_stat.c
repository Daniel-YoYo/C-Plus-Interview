#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

// 获取文件元数据
int main( int argc, char *argv[] )
{
    if( argv[1] == NULL )
    {
        perror("Command error");
        return -1;
    }

    struct  stat fileStat;

    // 获取文件元数据
    int ret = stat( argv[1], &fileStat );
    if( ret == -1 )
    {
        perror( "stat" );
        return -1;
    }

    // 显示文件元数据
    printf("Inode:%lu\n", fileStat.st_ino );
    printf("Hard Links:%u\n", fileStat.st_nlink );
    printf("Size:%ld\n", fileStat.st_size ); 
    printf("Time:%ld\n", fileStat.st_mtime );
    printf("Time:%s\n", ctime( &fileStat.st_mtime ) );

    return 0;
}