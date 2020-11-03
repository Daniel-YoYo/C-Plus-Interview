/*
 * @Author: your name
 * @Date: 2020-06-15 16:09:16
 * @LastEditTime: 2020-06-15 19:01:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit 
 * @FilePath: /C++/C++Note/C++Base(Tedu)/day2/overload.cpp
 */

/*  函数重载
1、定义
    (1)在相同作用域下,定义同名的函数,但是他们的参数有所区分(参数的个数、类型、顺序),
这样的多个函数构成重载关系.
    (2)函数能否构成重载关系,与返回值没有关系.
    (3)通过函数指针调用重载关系的函数,匹配的函数版本由函数指针的形参表决定,而不再由函数指针
的实参表决定.

2、函数重载匹配原则
    (1)调用重载关系函数,编译器会根据实参和形参的匹配程度,自动选择最优的函数版本.
    (2)当前g++编译器一般匹配规则:　内存优先级
    完全匹配 >= 常亮转换 >　升级转换 > 降级转换 = 过分升级转换 >　省略号匹配

3、函数重载匹配原理
    函数换名: g++编译器通过对函数进行换名,将参数的类型信息整合到新的函数名中,
解决函数重载和名字冲突的矛盾.

    函数: void fun( int i, double d )
    nm .o   列出目标文件中的符号
    C :     T fun
    C++ :   T _Z4funid; _Z:编译器标识, 4:函数名字节数, i=int, d=double

笔试题：　C++中　extern "C" 的作用
    在C++函数名前加入　extern "C" 声明,要求C++编译器在编译该函数时不做换名,
便于Ｃ程序去调用,方便C/C++混合编程的程序实现跨平台移植.
    extern "C" 声明的函数无法实现重载.

*/

#include <iostream>
using namespace std;

void bar( int i )
{ 
    cout << "bar( int )" << endl;
}

void bar( const char c )
{ 
    cout << "bar( const char c )" << endl;
}

void func( const char c )
{
    cout << "func( char )" << endl;
}

void func( int i )
{
    cout << "func( int )" << endl;
} 

void func( long long int lli )
{
    cout << "func( long long int )" << endl;
} 

void func( int i, float f )
{
    cout << "func( int, float )" << endl;
} 

void func( int i, int i2 )
{
    cout << "func( int, int )" << endl;
}

// 省略号匹配
void func( ... )
{
    cout << "func( ... )" << endl;
} 

// 雅元函数重载
void yafun(int)
{
    cout << "yafun(int)" << endl; 
}

void yafun(int,int)
{
    cout << "yafun(int,int)" << endl; 
}

int main( void )
{
    int i = 10;
    bar( i );     // func( int ),完全匹配      

    char c = 'Y';
    bar( c );      // func( char ),对实参增加常属性,常量转换
    
    short s = 10;   
    func( s );      // func( int ), short->int, 升级转换,增加内存,保证数据安全

    //func( 10, 3.14 );   // Error,  3.14:double, 在func(int ,int)和func(int, float )之间选择矛盾,故报错
    func( 10, 3.14f );    // func(int, float),完全匹配

    void (*pFunc)( int, int ) = func;   
    pFunc( 10, 3.14 );  // func( int, int ), 函数指针匹配重载函数版本,由函数指针形参表决定

    yafun(10);
    yafun(10,10);

    return 0;
}