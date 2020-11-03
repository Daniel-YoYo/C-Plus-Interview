//借助宏构建通用函数框架
#include <iostream>
using namespace std;

#define Max(T) T max_##T( T x, T y){ return x > y ? x : y; }

// 实例化宏,编译器预处理阶段根据具体类型生成不同的函数实体
Max(int)      // int max_int( int x, int y ){ return x > y ? x : y; }
Max(double)   // double max_double( double x, double y ){ ..... }
Max(string)   // string max_string( string x, string y ){ ..... }

// 用宏替换函数
#define MAX(T) max_##T

int main( void )
{
    int ix = 10, iy = 20;
    cout << max_int( ix, iy ) << endl;   // 调用由Max(int)宏实例化生产的函数
    cout << MAX(int)( ix, iy ) << endl;  // MAX(int) ==> max_int函数 

    double dx = 10.1, dy = 20.12;
    cout << '\n' << max_double( dx, dy ) << endl;  // 宏Max(double) ==> max_double函数
    cout << MAX(double)( dx, dy ) << endl;  // MAX(double) ==> max_double函数

    string strX = "Hello", strY = "World";
    cout << '\n' << max_string( strX, strY ) << endl;  //  宏Max(string) ==> max_string函数
    cout << MAX(string)( strX, strY ) << endl;  //  MAX(string) ==> max_string函数

    char cx[256] = "Hello", cy[256] = "World";
    cout << '\n' << MAX(string)( cx, cy ) << endl;  // 宏Max(string) ==> max_string函数
    
    return 0;
}