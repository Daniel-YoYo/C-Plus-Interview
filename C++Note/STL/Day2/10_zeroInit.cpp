// 零初始化
#include <iostream>
using namespace std;

// 类模板的零初始化成员变量
template<class T, class D>
class Test
{
    static T s_t;
    T m_t;
    D m_d;
public:
    // 无参构造函数零初始化
    Test():m_t( T() ), m_d( D() ){}
};
// 类模板静态成员变量零值初始化
template<class T, class D>T Test<T,D>::s_t = T();

class Integer
{
    int m_i;
public:
    friend ostream& operator<<( ostream& os, const Integer&that ){
        os << that.m_i;
        return os;
    }
};

template<class T>
void Func(){   
    T t = T();
    cout << "Func : " << t << endl;
}

template<class T>
void Func1(){   
    T t;
    cout << "Func1 : " << t << endl;
}

int main( void )
{   
    // 未零值初始化情况
    Func1<int>();
    Func1<Integer>();

    // 零值初始化
    Func<int>();
    Func<Integer>();
    return 0;
}