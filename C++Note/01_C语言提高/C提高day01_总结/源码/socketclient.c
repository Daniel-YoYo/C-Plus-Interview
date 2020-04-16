#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "socketclent.h"

// SocketClient API-1

// SocketClient Init
int socketclient_init(void **handle)
{
    return 0;
}

//SocketClient Send Data
int socketclient_send(void *handle, unsigned char *buf, int buflen)
{
    return 0;
}

//SocketClient Recive Data
int socketclient_recv(void *handle, unsigned char *buf, int *buflen)
{
    return 0;
}

//SocketClient Destory
int socketclient_destory(void *handle)
{
    return 0;
}

// SocketClient API-2

// SocketClient Init-2
int socketclient_init2(void **handle)
{
    return 0;
}

//SocketClient Send Data-2
int socketclient_send2(void *handle, unsigned char *buf, int buflen)
{
    return 0;
}

//SocketClient Recive Data-2
int socketclient_recv2(void *handle, unsigned char **buf, int *buflen)
{
    return 0;
}

int socketclient_Free(unsigned char **buf)
{
    return 0;
}

//SocketClient Destory-
int socketclient_destory2(void **handle)
{
    return 0;
}

int main( int argv, char **argc)
{
    printf( "Hello C++!" );

    getchar();
    
    return 0;
}