// 通过参数宏(宏函数)解决代码通用的实例
#include <iostream>
using namespace std;

// 宏函数
#define Max(x,y)    (x > y ? x : y)

int main( void )
{
    int ix = 10, iy = 20;
    // 预处理阶段时编译器做纯文本替换　
    cout << Max( ix, iy ) << endl;  // (ix > iy ? ix : iy)      

    double dx = 10.1, dy = 20.12;
    cout << Max( dx, dy ) << endl;  // (dx > dy ? dx : dy)

    string strX = "Hello", strY = "World";
    cout << Max( strX, strY ) << endl;  // (strX > strY ? strX : strY)

    char cx[256] = "Hello", cy[256] = "World";
    cout << Max( cx, cy ) << endl;  // 不做数据类型检查,比较的是指针cx和cy的地址大小！！！
    
    return 0;
}
