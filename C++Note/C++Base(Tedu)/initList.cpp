/*
 * @Author: your name
 * @Date: 2020-06-29 12:43:01
 * @LastEditTime: 2020-06-29 14:02:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/initList.cpp
 */ 
/**     构造函数初始化表
１、语法
    class 类名{
        类名(形参表):成员变量１(初值), 成员变量２(初值), 成员变量３(初值)
        {

        }

        类型 成员变量1;
        类型 成员变量2;
        类型 成员变量3;
    }

2、功能
    ->完成成员变量的初始化工作
    ->它和构造函数体内初始化有区别,初始化表在定义成员变量的同时初始化,
构造函数体内是先定义成员变量再赋值.

3、重点
    ->多数场景在构造函数初始化,和用初始化表初始化成员变量结果相同
    ->必须使用初始化表场景
    (1) 如果有类、类型成员变量(成员子对象),而该类没有无参构造函数,则必须通过初始化表来初始化该成员子对象.
    (2) 如果类中有"const"或"引用&"型成员变量,则必须在初始化表显示初始化.

    ->成员变量的初始化顺序,由声明的顺序决定,与初始化表的顺序无关,所以不要使用成员变量去初始化另一个成员变量 
  */ 

#include <iostream>
#include <cstring>

using namespace std;

class A
{
public:

    A( int id )
    {
        cout << "A Constructor :" << id << endl;
    }
    
};
 
class B
{
private:

    // "const"和"引用&"型成员变量,必须使用初始化表初始化
    const string name;
    const int& age;

    // 没有无参构造函数的成员子对象必须使用初始化表初始化
    A a;

public:

    B( const string& strIn, const int& ageIn ):name( strIn ), age( ageIn ),a( ageIn )
    {
        cout << "B Constructor :" << name << '\t' << age << endl;
    }
    
    ~B()
    {
        
    }
};


int main( void )
{
    B b = B("hello world", 25);

    return 0;
}
