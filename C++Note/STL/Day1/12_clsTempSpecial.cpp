// 类模板的全局特化
#include <iostream>
#include <cstring>
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

// 成员特化
template<>
char* const CMath< char* const >::sum()
{
    cout << "Member Specialized" << endl;
    return strcat( m_x, m_y );
}

// 全类特化(相当于针对某种特定数据类型重新定义一个类)
/*
template<>
class CMath< char* const >
{
    char* const chA;
    char* const chB;
public:
    CMath( char* const a, char* const b ):chA( a ), chB( b ){}
    char* const sum()
    {   
        cout << "Global Specialized" << endl;
        return strcat( chA, chB );
    }
};
*/

int main( void )
{
    int ix = 10, iy = 20;
    CMath<int> iCMath( ix, iy ); 
    cout << iCMath.sum() << endl;  

    double dx = 10.1, dy = 20.12;
    CMath<double> dCMath( dx, dy );
    cout << dCMath.sum() << endl;

    string strX = "Hello", strY = " World";
    CMath<string> strCMath( strX, strY );
    cout << strCMath.sum() << endl;

    // 针对 char* const 字符数组, 可以对类模板进行全局特化或局部特化
    char cx[] = "Hello", cy[] = " World";
    CMath< char* const > chCMath( cx, cy );
    cout << chCMath.sum() << endl;
    
    return 0;
}