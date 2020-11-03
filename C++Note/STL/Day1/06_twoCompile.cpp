// 函数模板二次编译
#include <iostream>
using namespace std;

//自定义类类型
class Integer
{
public:

    void print()
    {
        cout << "Integer::print" << endl;
    }
};

// 函数模板
template<class T>
void Max()
{
    //  已知类型调用
    Integer i;
    // 第一次编译时,编译器会检查调用是否有效
    i.print();      // ok
    // i.test();       // error

    // 未知类型调用
    T t;
    // 第一次编译时,编译器对未知类型的调用是先检查基本词法正确
    // 如果基本词法正确,该调用默认有效
    // t.sfadsaf();    // 第一次编译: ok; Max<Integer>();二次编译时无效: Error
    t.print();  // Max<Integer>() : ok
}

int main( void )
{

    // 用类型实参Integer实例化函数模板,将发生二次编译
    // 这时将对模板代码中的所有调用进行检查,确认所有调用是否有效
    Max<Integer>();

    return 0;
}