/*
 * @Author: your name
 * @Date: 2020-06-19 11:05:34
 * @LastEditTime: 2020-06-21 22:57:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/new.cpp
 */ 

/*  C++中new、delete和C中的malloc、free的区别
    (1)、new、delete是操作运算符,只能在C++中使用
    (2)、malloc、free是函数,C/C++都能使用
    (3)、new可以调用对象的构造函数,可以在分配内存的同时初始化,对应的delete调用相应的析构函数
    (4)、malloc仅仅分配内存,free仅仅回收内存,不会进行初始化
    (5)、new、delete返回的是指定数据类型指针,malloc、free返回的是void指针
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Test
{
    public:
        Test( const int& data )
        {
            a = data;
            cout << "Constructor : " << a << endl;
        }

        ~Test()
        {
            cout << "Destructor"<< endl;
        }

    private:

        int a;

};

int main( void ) 
{
    // malloc函数只分配内存
    int *p = (int *)malloc( sizeof( int ) );
    // 初始化
    *p = 123;
    cout << *p << endl;
    // free函数仅仅释放内存
    free( p );
    // malloc、free需要成对出现,防止野指针
    p = NULL;

    // new、delete返回指定类型数据指针
    // 自动调用类构造函数,分配内存同时初始化
    Test *tp = new Test( 10 );
    // 自动调用析构函数,释放内存
    delete tp;
    // 防止野指针
    tp = nullptr;

    // C++11new数组同时初始化
    int *pArr = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        cout << pArr[i] << ' ';
    }
    cout << endl;
    // 释放数组
    delete[] pArr;
    pArr = NULL;

    return 0;
}
