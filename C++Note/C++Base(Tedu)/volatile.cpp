/*
 * @Author: your name
 * @Date: 2020-07-14 15:00:22
 * @LastEditTime: 2020-07-14 15:05:43
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/volatile.cpp
 */ 

/**** Volatile 关键字测试程序 *****/

#include <iostream>

using namespace std;

int main( void )
{
    volatile const int ci = 100;
    int* pci = const_cast< int* >( &ci );

    *pci = 200;

    cout << "*pci :" << *pci << endl;
    cout << "ci :" << ci << endl;       // 如果加 volatile 修饰,数据就会更新为200;如果不加则是副本100

    cout << "pci :" << pci << endl;
    cout << "&ci :" << (void *)&ci << endl;

    return 0;
}
