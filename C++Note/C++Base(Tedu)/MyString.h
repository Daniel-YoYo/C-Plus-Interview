/*
 * @Author: your name
 * @Date: 2020-06-30 13:25:02
 * @LastEditTime: 2020-07-02 12:15:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/MyString.h
 */ 

/** 自定义实现　String　类
 * 
 * 
 */ 

#include <iostream>
#include <cstring>

using namespace std;

class MyString
{

public:

    MyString();
    
    // 构造函数
    MyString( const char* strIn );

    // 析构函数
    ~MyString();
    
    // 拷贝构造函数
    MyString( const MyString& that );

    // 所维护的内存区大小,不包括结束符'\0'
    size_t size();

    // 所维护的内存区字符串长度
    size_t lenght();

    // 转换成C语言字符串
    const char* c_str();

    // 拷贝赋值操作符函数
    MyString& operator= ( const MyString& that );

    // 操作符函数
    // +  
    MyString operator+ ( const MyString& that );
    MyString operator+ ( const char* strIn );

    // +=  
    MyString& operator+= ( const MyString& that );
    MyString& operator+= ( const char* strIn );

    // ==
    bool operator== ( const MyString& that );
    bool operator== ( const char* strIn );

    // !=
    bool operator!= ( const MyString& that );
    bool operator!= ( const char* strIn );
    
    // >
    bool operator> ( const MyString& that );
    bool operator> ( const char* strIn );

    // <
    bool operator< ( const MyString& that );
    bool operator< ( const char* strIn );

    // >=
    bool operator>= ( const MyString& that );
    bool operator>= ( const char* strIn );

    // <=
    bool operator<= ( const MyString& that );
    bool operator<= ( const char* strIn );

    // <<
    friend ostream& operator<< ( ostream&, const MyString& );
    
    // >>
    friend istream& operator>> ( istream&, MyString& );
    
    // []
    char operator[] ( const int& flag );
    
private:

    char* chStr;

};