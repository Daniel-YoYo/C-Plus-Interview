/*
 * @Author: your name
 * @Date: 2020-06-30 13:41:53
 * @LastEditTime: 2020-07-02 12:31:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/MyString.cpp
 */ 
#include "MyString.h"

using namespace std;

// 无参构造函数
MyString::MyString()
{
    chStr = NULL;
}

// 单参构造函数
MyString::MyString( const char* strIn )
{
    if( strIn == NULL )
    {
        chStr = NULL;
    }
    else
    {
        chStr = new char[ strlen( strIn ) ];
        strcpy( chStr, strIn );
    }
}

// 析构函数
MyString::~MyString()
{
    if( chStr != NULL )
    {
        delete[] chStr;
        chStr = NULL;
    }
}

// 拷贝构造函数
MyString::MyString( const MyString& that )
{
    if ( that.chStr != NULL )
    {
        chStr = new char[ strlen( that.chStr ) ];
        strcpy( chStr, that.chStr );
    }
    else
    {
        chStr = NULL;
    }
}

// 拷贝赋值操作符函数
MyString& MyString::operator= ( const MyString& that )
{
    // 防止自赋值
    if( this != &that )
    {
        // 释放旧资源
        if( chStr != NULL )
        {
            delete[] chStr;
        }

        // 分配新资源
        chStr = new char[ strlen( that.chStr) + 1 ];

        // 拷贝新数据
        strcpy( chStr, that.chStr );
    }

    // 返回自引用
    return *this;
}

// 操作符函数
// +  
MyString MyString::operator+ ( const MyString& that )
{
    return (*this + that.chStr);
}

MyString MyString::operator+ ( const char* strIn )
{
    if( strIn == NULL )
    {
        return *this;
    }

    // 自身不加字符串,返回临时变量
    char* tmp = new char[ strlen( this->chStr ) + strlen( strIn ) + 1];

    strcpy( tmp, chStr );
    strcat( tmp, strIn );

    cout << "MyString::operator+\t" << "this:" << this->chStr << "\tsize:" << strlen( this->chStr )
         << "\tthat:" << strIn <<  "\tsize:" << strlen( strIn )
         << "\tdest:" << tmp  << "\tsize:" << strlen( tmp ) << endl;
    MyString tmpStr( tmp );
    
    delete[] tmp;
    tmp = NULL;

    return tmpStr;
}

// +=  
MyString& MyString::operator+= ( const MyString& that )
{
    *this = *this + that;
    return *this;
}

MyString& MyString::operator+= ( const char* strIn )
{
    *this = *this + strIn;
    return *this;
}

// ==
bool MyString::operator== ( const MyString& that )
{

}

bool MyString::operator== ( const char* strIn )
{

}

// !=
bool MyString::operator!= ( const MyString& that )
{

}

bool MyString::operator!= ( const char* strIn )
{

}

// >
bool MyString::operator> ( const MyString& that )
{

}

bool MyString::operator> ( const char* strIn )
{

}

// <
bool MyString::operator< ( const MyString& that )
{

}

bool MyString::operator< ( const char* strIn )
{

}

// >=
bool MyString::operator>= ( const MyString& that )
{

}

bool MyString::operator>= ( const char* strIn )
{

}

// <=
bool MyString::operator<= ( const MyString& that )
{

}

bool MyString::operator<= ( const char* strIn )
{

}

// ostream
ostream& operator<< ( ostream& out, const MyString &str )
{
    if( str.chStr != NULL )
    {
        out << str.chStr;
    }

    return out;
}
// istream,一个是const另一个不是，根据变还是不变
istream& operator>> (istream& in, MyString& str)
{
    char tmp[100];// 临时字符串
    if( in >> tmp )
    {
        delete[] str.chStr;
        str.chStr = new char[ strlen( tmp ) + 1];
        strcpy(str.chStr,tmp);
    }
    
    return in;
}

// 所维护的内存区大小,不包括结束符'\0'
size_t MyString::size()
{
    return sizeof( chStr );
}

// 所维护的内存区字符串长度
size_t MyString::lenght()
{
    return strlen( chStr );
}

// 转换成C语言字符串
const char* MyString::c_str()
{
    return chStr;
}
    
int main( void )
{
    string s1 = "Hello ";
    string s2 = "World";

    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t+\t"  << s1 + s2 << endl;
    // cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t+=\t" << (s1 += s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t==\t"  << (s1 == s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t!=\t" << (s1 != s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t>\t"  << (s1 > s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t<\t" << (s1 < s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t>=\t"  << (s1 >= s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\t<=\t" << (s1 <= s2) << endl;
    cout << "s1 " << s1 << "\ts2 " << s2 <<  "\ts1[6]\t" << s1[6] << "\tsize\t" <<  s1.size()  << "\tLen\t" << s1.length() << endl;

    MyString ms1("Hello ");
    MyString ms2("World");
    MyString ms3( ms1 + "World" );

    cout << "ms1 " << ms1  << "\tms2\t"  << ms2 <<  "\t+\t"  << (ms1 + ms2 ) << endl;
    cout << "ms1 " << ms1  << "\tms2\t"  << ms2 <<  "\tms3\t"  << ms3 << endl;
    cout << "ms1 " << ms1  << "\tms2\t"  << ms2 <<  "\t+=\t"  << (ms1 += "Test" ) << endl;
    cout << "ms1 " << ms1  << "\tsize:\t" << ms1.size()  << "\tlen:\t" << ms1.lenght() << endl;
    
    return 0;
}