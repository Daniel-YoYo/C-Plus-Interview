#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// 文件重定向操作
// 通过复制标准输出文件描述符,实现文件写入和显示到终端 
int main( int argc, char *argv[] )
{
    if( argv[1] == NULL )
    {
        perror("Command error, example : ./a.out filename");
        return -1;
    }

    int tmpFd = -1;
    char *msg = "Redirect File Test......\n";
    // 文件操作权限
    int fFlag = O_RDWR | O_CREAT;
    // 设置文件权限(不设置的话,如果文件不存在,创建的文件没有访问权限)
    mode_t fMode = 0664;
    
    // 以可读可写方式打开文件,不存在时创建
    int fd = open( argv[1], fFlag, fMode );
    if( fd < 0 )
    {
        perror( "Open fiel error" );
        return -1;
    }

    // 复制标准输出文件描述符保存到临时文件描述符中
    tmpFd = dup( 1 );
    // 将文件的文件描述符复制到标准输出文件描述符中
    // 复制后1就是文件的文件描述符
    dup2( fd, 1 );
    close( fd );
    
    // 写数据到文件
    for (size_t i = 0; i < 10; i++)
    {
        write(1, msg, strlen( msg ) );
    }
    
    // 将临时文件描述符与系统标准输出描述符还原
    dup2( tmpFd, 1 );
    // 测试
    write( 1, msg, strlen( msg ) );
    // 关闭
    close( tmpFd );

    return 0;
}