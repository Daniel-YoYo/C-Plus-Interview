// 子类模板访问基类模板
#include <iostream>
using namespace std;

template<class T>
class Base
{
protected:
    int m_i;
    void print(){
        cout << "Base::m_i : " << m_i << endl;
    }
};

/******** 全局域********/
/*
int m_i = 0;
void print()
{
    cout << "print()" << endl;
}
*/
/*
编译器在第一次编译子类模板时,通常会认为基类类型不确定（未知类）
所以只在子类模板和全局域中搜索使用的表示符号
*/
template<class T>
class Device : public Base<T>
{
public:
    void foo()
    {
        // 子类模板访问基类模板
        // m_i = 10;   // error,第一次编译报错
        // print();    // error,第一次编译报错

        Base<T>::m_i = 10;  // ok
        Base<T>::print();   // ok

        this->m_i = 100; // OK
        this->print();  // OK
    }
};

int main( void )
{
    // 实例化基类模板
    Device<int> d;
    d.foo();
    return 0;
}
