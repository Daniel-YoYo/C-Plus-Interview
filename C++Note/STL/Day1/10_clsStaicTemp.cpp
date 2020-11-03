// 类模板静态成员
#include <iostream>
using namespace std;

// 类模板
template<class T>
class Test
{
    static int m_i;
    static T s_i;
public:
    void print(){ 
        cout << "&m_i : " << &m_i << "\t&s_i : " << &s_i << endl; }
    static void staticPrint(){ 
        cout << "&m_i : " << &m_i << "\t&s_i : " << &s_i << endl; }
};

// 类模板外初始化静态成员变量
template<class T> int Test<T>::m_i = 0;
template<class T> T Test<T>::s_i;

int main( void )
{
    Test<int> a, b;
    a.print();
    b.print();
    Test<int>::staticPrint();
    cout << "*********************************" << endl;
    Test<double> c, d;
    c.print();
    d.print();
    Test<double>::staticPrint();
}