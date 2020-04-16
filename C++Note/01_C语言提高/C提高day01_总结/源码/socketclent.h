
#pragma one

#ifdef  __cplusplus  
extern "C" {
#endif

// SocketClient API-1

// SocketClient Init
int socketclient_init(void **handle); //4

//SocketClient Send Data
int socketclient_send(void *handle, unsigned char *buf, int buflen); //2

//SocketClient Recive Data
int socketclient_recv(void *handle, unsigned char *buf, int *buflen); //2

//SocketClient Destory
int socketclient_destory(void *handle);


// SocketClient API-2

// SocketClient Init-2
int socketclient_init2(void **handle); //

//SocketClient Send Data-2
int socketclient_send2(void *handle, unsigned char *buf, int buflen);

//SocketClient Recive Data-2
int socketclient_recv2(void *handle, unsigned char **buf, int *buflen);
int socketclient_Free(unsigned char **buf);  //add

//SocketClient Destory-
int socketclient_destory2(void **handle);

#ifdef  __cplusplus
}
#endif