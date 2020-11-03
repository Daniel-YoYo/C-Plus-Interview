// 类模板的局部特化
#include <iostream>
using namespace std;

// 类模板
template<class T1, class T2>
class Partial
{
public:
    static void print()
    {
        cout << "1:Partial<T1, T2>" << endl;
    }
};

// 类模板局部特化1
template<class T1>
class Partial<T1, short>
{
public:
    static void print()
    {
        cout << "2:Partial<T1, short>" << endl;
    }
};

// 类模板局部特化2
template<class T>
class Partial<T, T>
{
public:
    static void print()
    {
        cout << "3:Partial<T, T>" << endl;
    }
};

// 类模板局部特化3
template<class T1, class T2>
class Partial<T1*, T2*>
{
public:
    static void print()
    {
        cout << "4:Partial<T1*, T2*>" << endl;
    }
};

int main( void )
{   
    Partial<double, int>::print();      // 1:Partial<T1, T2>
    Partial<double, short>::print();    // 2:Partial<T1, short>
    Partial<double, double>::print();   // 3:Partial<T, T>
    //Partial<short, short>::print();   　// Error,编译器在特化版本1和2之间难以抉择
    //Partial<short*, short*>::print();   // Error,编译器在特化版本2和3之间难以抉择

    return 0;
}