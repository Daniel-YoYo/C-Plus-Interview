//依赖模板参数访问类模板的成员函数的函数模板
#include <iostream>
using namespace std;

template<class T>
class A
{
public:
    // 模板型成员函数模板
    template<class R>void foo()
    {
        cout << "A::foo()" << endl;
    }
};

// 函数模板
template<class T>void Func()
{   
    // 类模板A实例化产生的未知类,定义对象a
    A<T> a;
    // 访问类模板中的成员函数模板foo();
    // 原因: 编译器在第一次编译时无法解析函数模板的类型参数列表的<>而报告编译错误
    // a.foo<int>();       // error
    // 解决办法: 在成员函数模板之前增加template关键字,\
    意在告诉编译器其后是一个函数模板示例，编译器就可以正确理解<>了
    a.template foo<int>();  // OK
}
 
int main( void )
{
    // 实例化调用
    Func<int>();
    return 0;
}