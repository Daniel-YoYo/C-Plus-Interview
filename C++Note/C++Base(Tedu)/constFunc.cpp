/*
 * @Author: your name
 * @Date: 2020-06-29 15:01:06
 * @LastEditTime: 2020-06-29 15:38:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/constFunc.cpp
 */ 
/**
 *  常函数
1、定义
    在一个普通成员函数后加 const关键字修饰,这样的成员函数为常函数.
const修饰的是 this指针.

2、语法
    clas 类名{
        返回类型 函数名(形参表) const {函数体}
    };

3、作用
    (1)常函数修饰隐藏的this指针,不能在常函数中修改成员变量的值

注：
    ->mutable修饰的成员变量可以在常函数中被修改
    ->常类型转换const_cast<>()可以在常函数中修改成员变量

    (2)常对象只能调用常函数,非常对象可以调用非常函数和常函数.常对象包括常指针和常引用

    (3)函数名和形参表相同的成员函数,其常函数版本和非常函数版本可以构成重载关系,
常对象调用常函数版本,非常对象调用非常函数版本.

 */
#include <iostream>
using namespace std;

class Test
{
private:

public:

    Test(){
        cout << sizeof( int ) << endl;
        cout << sizeof( int* ) << endl;
    }
    ~Test(){}

    // 函数原型 void func( const Test* this )
    void func() const
    {
        cout << "const func()" << endl;
    }

    //函数原型　void func( Test* this )
    void func()
    {
        cout << "func()" << endl;
    }

    void func1()
    {
        cout << "func1()" << endl;
    }
};

int main( void )
{
    // 函数名和形参表相同的成员函数,其非常函数版本和常函数版本可以构成重载关系
    Test t;
    t.func();   // func(), 非常对象调用非常函数版本
    t.func1();  // func1(),非常对象即可调用常函数也可调用非常函数

    // 常对象包括常指针和常引用
    const Test* tp = &t;
    tp->func();    // const func(), 常对象调用常函数版本
    //tp->func1();   // Error, 常对象只能调用常函数

    const Test& rt = t;
    rt.func();     // const func(), 常对象调用常函数版本
    //rt.func1();    // Error, 常对象只能调用常函数

    return 0;
}