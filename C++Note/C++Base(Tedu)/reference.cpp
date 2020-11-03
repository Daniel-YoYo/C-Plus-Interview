/*
 * @Author: your name
 * @Date: 2020-06-21 14:34:29
 * @LastEditTime: 2020-06-21 16:15:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/reference.cpp
 */ 
/** C++引用
 1、定义
    引用即别名,引用就是指定变量的别名,对引用的操作与对该变量的操作完全相同.
    语法: 类型 & 引用名 = 变量名;   例如：　int a = 100; int& b = a; b是a的引用.
    (1)引用定义时必须初始化,初始化后不能再修改引用目标.
    (2)引用的类型与引用目标类型要一致.
    (3)在高级语言层引用不占内存空间.

2、分类
(1)普通引用
    定义时不使用const关键字修饰的引用即为普通引用.
    普通引用只能引用左值.
(2)常引用
    定义时使用const关键字修饰的普通引用,称为常引用,不能通过常引用修改引用目标数据.
    常引用又叫万能引用,既可以引用左值又可以引用右值.

3、引用常用场景
(1)引用型函数参数
    将引用作为函数参数,这时形参变量就是实参变量的别名,这样可以减少函数调用的内存开销,提高函数的传参效率和代码执行效率.
    当需要修改实参数据时,可以使用普通引用做函数参数
    当不需要修改实参数据时,使用常引用做函数参数

(2)引用做函数返回值
    可以将函数的返回值类型声明为引用,变量函数返回值所带来的内存开销(将亡右值)
    为了避免在函数外部修改引用的目标变量.可以加const关键字修饰.
    注：不要从函数中返回局部变量的引用,因为所引用的内存会在函数调用结束后被释放,使用很危险,
可以返回成员变量,静态变量,全局变量的引用.

面试题：　引用与指针的区别？
(1)从C语言的角度看,引用的本质就是指针常量,底层汇编代码一样
(2)指针:定义时可以不初始化,初始化后也可以更改指定对象.
   引用: 定义时必须初始化,初始化后不能更改引用目标.
********扩展内容*************
(3)可以定义指针的指针(二级指针),但是不能定义引用的指针(引用在高级语言层不占用内存,所以无法定义一个指向引用的指针)
(4)可以定义指针的引用,但是不能定义引用的引用
(5)可以定义指针数组、数组指针、数组引用
(6)但是不能定义引用数组(原因:数组的内存是连续性的,引用数组不能保证内存连续性)
(7)可以定义函数引用,和函数指针类似
*/

#include <iostream>
using namespace std;

// 引用做函数参数和返回值
const int& func( const int& a, const int& b )
{
    // 不能使用局部变量做函数的引用型返回值
    static int c = a + b;
    return c;
}

void func1( int a, int b )
{
    cout << a + b << endl;
}

int main( void )
{
    int a = 10, b = 15, c = 20, d = 30;

    int& ar = a;        //ko,普通引用
    const int& ca = a;  //ok,常引用

    int* ap = &a;
    int** app = &ap;    //ok,二级指针
    //int& *arp = &ar;    //error,引用的指针
    int* &apr = ap;     // ok,指针的引用
    //int&& arr = ar;     // error,不能定义引用的引用
    //int&& s = 100;      // 在ｃ++11支持这种右值引用(c++98不支持)

    int arr[4] = {a, b, c, d};              
    int* parr[4] = {&a, &b, &c, &d};    // 指针数组
    int (*arrp)[4] = &arr;              // 数组指针
    cout << "Array Pointer :" << arrp[0][0] << ' ' << arrp[0][1] << ' ' << arrp[0][2] << ' ' << arrp[0][3] << endl;

    int (&arrr)[4] = arr;       // OK, 数组引用,arrr是arr数组的别名
    cout << "Array Reference :" << arrr[0] << ' ' << arrr[1] << ' ' << arrr[2] << ' ' << arrr[3] << endl;
    
    //int& rarr[2] = {ar, ca};    // Error,引用数组,(原因:数组的内存是连续性的,引用数组不能保证内存连续性)
    
    int res = func( a, b );
    cout <<  res << endl;

    // 函数指针
    void (*funcp)(int, int) = func1;
    funcp(1,2);
    
    // 函数引用
    void (&funcr)(int,int) = func1;
    funcr( 3,4);    
    
    return 0;
}