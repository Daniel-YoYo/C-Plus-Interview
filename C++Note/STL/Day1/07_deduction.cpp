// 函数模板的隐式推断
#include <iostream>
#include <typeinfo>
using namespace std;

// 函数模板
template<class T>
void Max(const T& x, const T& y )
{
    cout << "x : " << typeid( x ).name() << "\ty : " << typeid( y ).name() << endl;
}

//自定义类类型
class Integer
{
    int m_i;
public:
    Integer( const int& i ):m_i( i ){}
};

template <class T, class D>
void Func( D d ){}

template <class R, class T>
R Bar( T t ){ R r; return r; }

int main( void )
{
    int ix = 10, iy = 20;
    Max( ix, iy );  // 隐式推断, Max<int>(ix, iy);
    double dx = 10.1, dy = 20.12;
    Max( dx, dy );  // 隐式推断, Max<double>(ix, iy);
    string strX = "Hello", strY = "World";
    Max( strX, strY );  // 隐式推断, Max<string>(ix, iy);
    Integer inteX = 100, inteY = 200;
    Max( inteX, inteY );   // 隐式推断, Max<Integer>(ix, iy);

    // 不能隐式推断的三种情况
    // 1 不是全部模板参数都与调用参数的类型相关
    // Func( ix );     // 类型形参D可以推断为int类型, T的类型无法确定, Error
    Func<double>( ix );     // T : double, D : int;  OK

    // 2 隐式推断不支持隐式类型转换
    // Max( ix, dx );          // 无法确定T的类型, error
    Max( ix, int( dy ) );      // 强转 ok

    // 3 返回值类型不支持隐式推断
    // Bar( ix );         // T:int; R类型无法推断, Error
    Bar<int>( ix );       // R:int; T:int;  ok

    return 0;
}