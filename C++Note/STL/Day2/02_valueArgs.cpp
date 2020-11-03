// 普通数值做类模板的类型参数
#include <iostream>
using namespace std;

// 类模板,普通数值做类型参数
template <class T, size_t S = 10> 
class Array
{
    T m_arr[ S ];
public:
    T& operator[]( size_t i )
    {
        return m_arr[i];
    }

    size_t size()
    {
        return S;
    }
};

int main( void )
{
    Array< int, 8 > a;         // 一维数组
    for (size_t i = 0; i < a.size(); i++)
        a[i] = i + 1;

    for ( size_t i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n***********************************"<< endl;

    Array< Array<int>, 8 > b;  // 类模板的递归实例,二维数组
    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < 10; j++)
            b[i][j] = i*10+j+1;
    }

    for (size_t i = 0; i < b.size(); i++)
    {
        for (size_t j = 0; j < 10; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}