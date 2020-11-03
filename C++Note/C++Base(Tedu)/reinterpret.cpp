/*
 * @Author: your name
 * @Date: 2020-07-14 15:20:36
 * @LastEditTime: 2020-07-14 15:30:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/reinterpret.cpp
 */ 
/** 测试 reinterpret_cast 重解释转换 *****/
#include <iostream>
using namespace std;

struct Acc
{
    char type[5];
    char name[9];
    char passwd[7];
};

int main( void )
{   
    // \000 -> \0 + 00(结束标识) 
    char text[] = "0001\00012345678\000123456";

    // 重解释类型转,将char *转换成 Acc*
    Acc *pAcc = reinterpret_cast< Acc* >( text );
    cout << pAcc->type << endl;
    cout << pAcc->name << endl;
    cout << pAcc->passwd << endl;
    return 0;
}
