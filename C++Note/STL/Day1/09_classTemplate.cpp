// 类模板
#include <iostream>
using namespace std;

// 类模板
template<class T>
class CMath
{
    T m_x;
    T m_y;
public:
    CMath( const T& x, const T& y ):m_x(x), m_y(y){}
    T sum();
};

// 类模板外实现函数定义
template<class T>
T CMath<T>::sum()
{
    return m_x + m_y;
}

// 自定义类
class Integer
{
    int m_i;
public:
    Integer( const int& i ):m_i(i){}

    Integer operator+( const Integer& that ) const
    {
        return m_i + that.m_i;
    }

    friend ostream& operator<<( ostream& os, const Integer& that )
    {
        return os << that.m_i;
    }
};

int main( void )
{
    int ix = 10, iy = 20;
    // 实例化类模板并创建对象iCMath;
    CMath<int> iCMath( ix, iy );
    // 类模板成员函数只有被调用时才实例化成真正的函数    
    cout << iCMath.sum() << endl;  

    double dx = 10.1, dy = 20.12;
    CMath<double> dCMath( dx, dy );
    cout << dCMath.sum() << endl;

    string strX = "Hello", strY = "World";
    CMath<string> strCMath( strX, strY );
    cout << strCMath.sum() << endl;

    // 某些类型虽然并没有提供类模板所需要的全部功能
    // 但照样可以实例化该类模板
    // 只要不直接或间接调用那些依赖于该操作符的成员函数即可
    Integer inteX = 100, inteY = 200;
    CMath<Integer> integerCMath( inteX, inteY );
    cout << integerCMath.sum() << endl;
}