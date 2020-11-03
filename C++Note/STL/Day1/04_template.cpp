// 函数模板实例化
#include <iostream>
using namespace std;

// 函数模板
template<class T>
T Max( const T& x, const T& y )
{
    return  x > y ? x : y; 
}

int main( void )
{

    int ix = 10, iy = 20;
    // 实例化函数实体 int Max(const int& x, const int& y){ return x > y ? x : y; } 
    cout << Max<int>( ix, iy ) << endl;  

    double dx = 10.1, dy = 20.12;
    // 实例化函数实体 double Max(const double& x, const double& y){ return x > y ? x : y; } 
    cout << Max<double>( dx, dy ) << endl;

    string strX = "Hello", strY = "World";
    // 实例化函数实体 string Max(const string& x, const string& y){ return x > y ? x : y; } 
    cout << Max<string>( strX, strY ) << endl;

    char cx[256] = "Hello", cy[256] = "World";
    // 实例化函数实体 string Max(const string& x, const string& y){ return x > y ? x : y; }  
    cout << Max<string>( cx, cy ) << endl;

}