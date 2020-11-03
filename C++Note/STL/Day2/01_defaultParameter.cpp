/*
 * @Author: your name
 * @Date: 2020-08-24 12:58:52
 * @LastEditTime: 2020-09-02 22:46:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/STL/Day1/defaultParameter.cpp
 */
#include <iostream>
#include <typeinfo>

using namespace std;

template < class T, class D = short >
class A
{
    T m_t;
    D m_d;
public:
    void print()
    {
        cout << "T :" << typeid( m_t ).name() << "\nD :" << typeid( m_d ).name() << endl;
    }
};

int main( void )
{

    A<double, double> a;
    a.print();

    A<int> b;
    b.print();
    return 0;
}