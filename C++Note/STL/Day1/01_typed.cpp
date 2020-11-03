// 在面对数据类型不一致,抽象层面一致时,初级方法
#include <iostream>
using namespace std;

int max_int( const int& x, const int& y )
{
    return x > y ? x : y;
}

double max_double( const double& x, const double& y )
{
    return x > y ? x : y;
}

string max_string( const string& x, const string& y )
{
    return x > y ? x : y;
}

int main( void )
{
    int ix = 10, iy = 20;
    cout << max_int( ix, iy ) << endl;

    double dx = 10.1, dy = 20.12;
    cout << max_double( dx, dy ) << endl;

    string strX = "Hello", strY = "World";
    cout << max_string( strX, strY ) << endl;
    
    return 0;
}