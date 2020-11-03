// 类模板的递归实例化
#include <iostream>
using namespace std;

template <class T> class Array
{
    T m_arr[ 10 ];
public:
    T& operator[]( size_t i )
    {
        return m_arr[i];
    }
};

int main( void )
{
    Array< int > a;         // 一维数组
    for (size_t i = 0; i < 10; i++)
        a[i] = i + 1;

    for ( size_t i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << "\n***********************************"<< endl;

    Array< Array<int> > b;  // 类模板的递归实例,二维数组
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
            b[i][j] = i*10+j+1;
    }

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}