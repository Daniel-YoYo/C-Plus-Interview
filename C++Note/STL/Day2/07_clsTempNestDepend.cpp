// 模板的嵌套依赖
#include <iostream>
using namespace std;
 
class A
{
public:
    // 嵌套类B
    class B
    {
        public:
            void foo()
            {
                cout << "A::B::foo()" << endl;
            }
    };  
};

// 函数模板
template<class T>void Func()
{
    // 1-当T为类A时,由于类B是A的嵌套类,理论上这样写就没问题,但是错误.
    // 2-在第一次编译模板代码时, 模板的类型形参的具体类型尚不明确
    // 编译器将把模板类型形参的嵌套类型理解为某个未知类型的静态成员变量,
    // 因此编译器看到使用这样的标识符声明变量时就会报告错误，这就叫嵌套依赖
    // T::B b;          // 模板第一次编译会报错,Error
    typename T::B b;    // 对于嵌套类型必须加typename修饰, 编译OK
    b.foo();    
}
 
int main( void )
{
    // 实例化调用
    Func<A>();
    return 0;
}