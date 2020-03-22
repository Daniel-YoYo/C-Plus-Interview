#include <iostream>
#include <cstdio>
#include <csetjmp>

using namespace std;

// 声明全局跳转变量
jmp_buf g_env;

class A
{

public:
    A( void )
    {
        cout << "A : Constructor" << endl; 
    }

    ~A( void )
    {
        cout << "A : Destructor" << endl;
    }
};

int func3( void )
{
    A a;
    FILE * fp = fopen("none.txt", "r" );
    if( fp == NULL )
    {
        // 远程跳转
        longjmp( g_env, -1 );
    }

    fclose( fp );
    return 0;
}

int func2( void )
{
    A a;

    if( func3() == -1 )
    {
        return -1;
    }
    return 0;
}

int func1( void )
{
    A a;

    if( func2() == -1 )
    {
        return -1;
    }

    return 0;
}

int main( void )
{
    // 设置远程跳转点
    if( setjmp( g_env ) == -1 )
    {
        cout << "File Open Failed!" << endl;
        return -1;
    }

    if( func1() == -1 )
    {
        return -1;
    }

    return 0;
}