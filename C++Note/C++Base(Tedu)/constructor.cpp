/*
 * @Author: your name
 * @Date: 2020-06-21 22:54:37
 * @LastEditTime: 2020-06-22 18:19:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/constructor.cpp
 */ 
/** C++构造函数
 1、定义
    每个类都分别定义了它的对象被初始化的方式,类通过一个或几个特殊的成员函数来控制
其对象的初始化过程,这些函数被称为---构造函数
    类被创建时要调用相应的构造函数初始化
    构造函数名和类型一致,构造函数可以重载、也可以带有缺省参数
 
 2、应用 
 (1)缺省(默认)构造函数/无参构造函数
    ->如果类中没有定义任何构造函数,编译器会提供一个缺省构造函数
    ->对类 类型成本变量(成员子对象),会自动调用相应类的无参构造函数来初始化
成员子对象将先于父对象构造初始化.
    ->如果类中定义了构造函数,无论是否有参数,编译器将不再提供缺省构造函数
 
 (2)类型转换构造函数/单参构造函数
    ->只有一个参数的构造函数,可以将源类型隐世转换成目标类型(不建议隐世转换,会降低代码可读性)
    ->explicit关键字修饰的类型转换构造函数,将强制要求使用显示转换构造对象
 
 (3)拷贝构造函数
    ->用一个已经存在的对象构造同类型的副本对象,本调用该类的拷贝构造函数
    ->如果一个类没有定义任何拷贝构造函数,那么编译器会为该类提供一个缺省的拷贝构造函数
    ->拷贝构造过程中,对基本类型的成员变量,按字节复制;对类类型成员变量(成员子对象),调用
相应类的拷贝构造函数来初始化.
    ->一般情况不需要自己定义拷贝构造函数,因为编译器提供的缺省的构造函数已经很好了

---->拷贝构造函数调用的时机
    1、用已经定义的对象做同类型对象的构造实参
    2、以对象的形式向函数传递参数
    3、从函数中返回对象(存在被编译器优化的情况)

 */

#include <iostream>
#include <string>
using namespace std;

struct Info
{
    string name;
    unsigned int age;
    unsigned int id;
};

class StudentInfo
{
public:

    string name;
    unsigned int age;
    unsigned int id;
    
};

class Student
{

public:
    Student();
    explicit Student( const StudentInfo& info_In );
    // 拷贝构造函数用explicit修饰后,无法隐式拷贝构造
    // Student s1 = s;  // 隐式拷贝构造
    // Student s1(s);   // 显式拷贝构造
    Student( const Student& that );

    ~Student();

    void printfInfo();

private:

    StudentInfo info;

};

Student::Student()
{
    cout << "Default Constructor" << endl;
}

Student::Student( const StudentInfo& info_In )
{
    this->info = info_In;
    cout << "Type Conversion Constructor" << endl;
}

Student::Student( const Student& that )
{
    cout << "Copy Conversion Constructor" << endl;
    info = that.info;
}

Student::~Student()
{
    cout << "Destructor" << endl;
}

void Student::printfInfo()
{
    cout << "Name:" << info.name << '\t' 
         << "Age:" << info.age << '\t'
         << "ID:" << info.id << endl;
}

int main( void )
{
    StudentInfo lwy;
    lwy.name = "YoYo";
    lwy.age = 25;
    lwy.id = 10086;

    Student s(lwy);
    s.printfInfo();

    Student s1 = s;
    s1.printfInfo();

    return 0;
}