// 成员函数模板
#include <iostream>
#include <typeinfo>

using namespace std;

template <class T>
class A
{
public:
    // 类模板成员函数
    template<class B>void print();
};

// 类模板成员函数的类外实现
template<class T>
template<class B>
void A<T>::print()
{      
    cout << "A<" << typeid( T ).name() << ">::print<" \
         << typeid( B ).name() << ">" << endl;
}

int main( void )
{
    A<double> a;
    // 成员函数模板实例化调用
    a.print<int>();

    A<int> b;
    // 成员函数模板实例化调用
    b.print<double>();
    return 0;
}