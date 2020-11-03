// 模板型模板参数(用类模板做类模板的模板形参)
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

//
template<class D, template<class R>class C>
class Sum
{
    C<D> m_s;       // C = Array, Array<D> m_s;
public:

    Sum( C<D> const& s ):m_s( s ){}

    D sum()
    {
        D d = 0;
        for (size_t i = 0; i < 10; i++)
            d += m_s[i];

        return d;
    }
};

int main( void )
{
    Array< int > a;
    for (size_t i = 0; i < 10; i++)
        a[i] = i + 1;
    
    // 对数组a求和
    Sum< int, Array > s( a );
    cout << s.sum() << endl;

    return 0;
}