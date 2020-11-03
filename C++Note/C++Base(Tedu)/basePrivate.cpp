/*
 * @Author: your name
 * @Date: 2020-07-14 13:49:16
 * @LastEditTime: 2020-07-14 13:59:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/basePrivate.cpp
 */ 
#include <iostream>
using namespace std;
 
class Base
{
private:
    virtual void f0() { cout << "Base::f0()...." << endl; }
    virtual void f1() { cout << "Base::f1()...." << endl; }
    virtual void f2() { cout << "Base::f2()...." << endl; }
};
 
class Derive : public Base{};
 
typedef void(*Fun)(void);
 
int main(int argc, char* argv[])
{
    Derive d;
    Fun  pFun0 = (Fun)*((int*)*(int*)(&d)+0);
    Fun  pFun1 = (Fun)*((int*)*(int*)(&d)+1);
    Fun  pFun2 = (Fun)*((int*)*(int*)(&d)+2);
    pFun0();
    pFun1();
    pFun2();
 
    return 0;
}