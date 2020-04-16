#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
#include "features.h"

/** 库加载的两种方法:
 *  1、动态加载如下代码所示,使用dlopne、dlsym、dlclose、dlerror
 *  2、直接调用,编译链接,　g++ main.cpp -L(跟库路径) -l(跟库名)
 **/
/** 动态加载动态库操作流程
 *  1、dlopen懒绑定方式打开动态库文件,dlerror获取最近错误信息
 *  2、dlsym根据句柄和函数名在动态库中函数的入口地址并返回
 *  3、根据函数入口地址,调用函数
 *  4、动态库使用完关闭dlclose
 **/
int main()  
{
    void *dlHandle = NULL;

    int a = 10, b = 2;

    // 根据动态库的头文件,定义函数指针
    int (*add)(int , int );
    int (*sub)(int , int );
    int (*mul)(int , int );
    int (*div)(int , int );

    // 以懒绑定的方式打开 libfeatures.so　动态库
    dlHandle = dlopen( "./libfeatures.so", RTLD_LAZY );

    // 判断是否打开成功
    if( dlHandle == NULL )
    {
        printf("%s \n", dlerror() );
        return -1;
    }

    printf("Load libfeatures.so Success!\n");

    // 加载成功,获取函数的入口地址
    add = dlsym( dlHandle, "addNum" );
    if( add == NULL )
    {
        printf("%s \n", dlerror() );
        return -1;
    }

    sub = dlsym( dlHandle, "subNum" );
    if( sub == NULL )
    {
        printf("%s \n", dlerror() );
        return -1;
    }

    mul = dlsym( dlHandle, "mulNum" );
    if( mul == NULL )
    {
        printf("%s \n", dlerror() );
        return -1;
    }

    div = dlsym( dlHandle, "divNum" );
    if( div == NULL )
    {
        printf("%s \n", dlerror() );
        return -1;
    }
    
    printf("dlsym Success!\n");

    // Call function interface
    printf("%d+%d=%d\n", a, b, add( a, b ) );
    printf("%d-%d=%d\n", a, b, sub( a, b ) );
    printf("%d*%d=%d\n", a, b, mul( a, b ) );
    printf("%d/%d=%d\n", a, b, div( a, b ) );
    
    // 使用完要关闭,判断是否关闭成功
    if( dlclose( dlHandle ) != 0 )
    {
        printf("%s \n", dlerror() );
        return -2;
    }

    printf("Close libfeatures.so Success!\n");

    return 0;
}