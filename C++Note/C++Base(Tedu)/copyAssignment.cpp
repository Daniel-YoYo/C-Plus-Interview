/*
 * @Author: your name
 * @Date: 2020-07-07 21:11:46
 * @LastEditTime: 2020-07-09 13:37:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/copyAssignment.cpp
 */ 
/****      拷贝赋值操作符函数
 * １、如果类中未定义拷贝赋值操作符函数,编译器将会提供缺省拷贝赋值操作符函数
 * 2、当类中有指针变量时,缺省拷贝赋值函数会存在浅/深拷贝问题,会造成数据共享
 * 3、为解决深浅拷贝问题,需要自定义拷贝赋值操作符函数和拷贝构造函数
 * 
 * 
 * 
 */

#include <iostream>
#include <cstring>
#include <typeinfo>

using namespace std;


class Base
{
public:
    Base( int idIn ):m_id( idIn )
    {
        cout << "Base::Base()" << endl;
    }
    ~Base(){}

    int m_id;
};


class CopyAssignment : public Base
{
private:
    
    char* name;
    int age;

public:
    
    CopyAssignment( const char* nameIn = "", const int& ageIn = 0 ):age( ageIn ),Base( 0 )
    {
        cout << "CopyAssignment::CopyAssignment()" << endl;
        name = new char[ strlen( nameIn ) + 1 ];
        strcpy( name, nameIn ); 
    }
    
    ~CopyAssignment()
    {
        cout << "CopyAssignment::~CopyAssignment()" << endl;
        delete[] name;
        name = NULL;
    }

    void getInfo()
    {
        cout << "Name:" << name << "\tAge:" << age << "\tID:" << m_id << endl;
    }

    // 自定义拷贝构造函数,解决拷贝构造时深浅拷贝问题
    // 使用向上造型解决基类子对象的构造问题,拷贝构造
    // 缺省拷贝构造和拷贝赋值在复制子类部分之前会先复制其基类部分
    CopyAssignment( const CopyAssignment& that ):Base( that )
    {
        name = new char[ strlen( that.name ) + 1];
        strcpy( name, that.name ); 
        age = that.age;
    }

    // 自定义拷贝赋值函数,避免在拷贝赋值时深浅拷贝问题
    CopyAssignment& operator = ( const CopyAssignment& that )
    {
        cout << "CopyAssignment::operator=" << endl;
        if( &that != this )
        {
            delete[] name;
            name = new char[ strlen( that.name ) + 1];
            strcpy( name, that.name ); 

            // 除指针变量外,其他成员变量也要赋值
            age = that.age;

            // 如果自己提供拷贝构造和拷贝赋值,就需要手动地对基类部分进行拷贝构造和拷贝赋值,
            // 否则该部分将会以缺省方式被构造或不进行赋值.
            // 向上造型,拷贝赋值
            Base::operator=( that );
        }

        return *this;
    }
};


int main()
{
    CopyAssignment c1( "YoYo", 25 );
    c1.getInfo();

    // 向上造型
    Base *bp = &c1;
    bp->m_id = 10086;
    c1.getInfo();

    CopyAssignment c2;
    c2 = c1;            // 拷贝赋值
    c2.getInfo();
    // 向上造型
    bp = &c2;
    bp->m_id = 10000;
    c2.getInfo();   // 数据同步更新到子类

    CopyAssignment c3 = c2; // 拷贝构造,不定义拷贝构造函数,会有double free风险
    c3.getInfo();

    cout << typeid( c3 ).name() << endl;

    return 0;
}