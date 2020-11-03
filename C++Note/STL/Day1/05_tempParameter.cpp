// 函数模板类型实参
#include <iostream>
using namespace std;

// 函数模板
template<class T>
T Max( const T& x, const T& y )
{
    return  x > y ? x : y; 
}

//自定义类类型
class Integer
{
    int m_i;
public:
    Integer( const int& i ):m_i( i ){}

    bool operator >( const Integer& that ) const
    {
        return m_i > that.m_i;
    }

    friend ostream& operator<<( ostream& os, const Integer& that )
    {
        return os << that.m_i;
    }
};

int main( void )
{

    int ix = 10, iy = 20;
    cout << Max<int>( ix, iy ) << endl;  

    double dx = 10.1, dy = 20.12;
    cout << Max<double>( dx, dy ) << endl;

    string strX = "Hello", strY = "World";
    cout << Max<string>( strX, strY ) << endl;

    Integer inteX = 100, inteY = 200;
    // 当Integer类中不支持 '>' 和 '<<'　操作符时,编译会报错
    // 需要操作符重载'>' 和 '<<'
    cout << Max<Integer>( inteX, inteY ) << endl;

}