// 函数模板的重载
#include <iostream>
using namespace std;

// 普通函数
void Max( int x, int y )
{
    cout << "1:Max(int, int)" << endl; 
}
// 函数模板
template < class T >
void Max( const T& x, const T& y )
{
    cout << "2:Max(T,T)" << endl;
}

// 特殊版本
template < class T >
void Max( T* x, T* y )
{
    cout << "3:Max(T*, T*)" << endl;
}

int main( void )
{
    int ix = 10, iy = 20;
    Max( ix, iy );  // 编译器优先选择普通函数, 1:Max(int,int)
    Max<>(ix, iy ); // 强行通知编译器选择函数模板. 2:Max(T, T)
    
    double dx = 10.1, dy = 100.2;
    // 函数模板将产生更好的数据匹配度的函数实例, 2:Max(T, T)
    Max( dx, dy ); 
    // 函数模板的实例化不支持隐式类型转换, 1:Max(int, int ) 
    Max( ix, dx );  
    // 如果让编译器隐式推断类型,编译器会选择约束性强的版本
    Max( &ix, &iy );    // 3:Max(T*, T*);

    return 0;
}