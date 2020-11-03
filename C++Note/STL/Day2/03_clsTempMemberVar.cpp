// 模板型成员变量
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

template<class D>
class Sum
{
    // 模板型成员变量,必须是有一个类模板实例化的未知类类型
    Array<D> m_arr; 
public:

    Sum( Array<D> const& s):m_arr( s ){}

    D sum()
    {
        D d = 0;
        for (size_t i = 0; i < 10; i++)
            d += m_arr[i];

        return d;
    }
};

int main( void )
{
    Array< int > a;
    for (size_t i = 0; i < 10; i++)
        a[i] = i + 1;
    
    Sum< int > s( a );
    cout << s.sum() << endl;

    return 0;
}