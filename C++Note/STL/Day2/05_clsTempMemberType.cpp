// 模板型成员类型
#include <iostream>
using namespace std;
 
template<class X>
class A
{
public:
   template <class Y> class B
   {
       public:
             template <class Z> class C; // 嵌套的类模板C
   }; // 嵌套的类模板B
}; // 类模板A
 
// 类模板C类外实现
template<class X>
template<class Y>
template <class Z> 
class A<X>::B<Y>::C
{
public:
   template<class T>void foo();
};

// 类外实现 void A<X>::B<Y>::C<Z>::foo();
template<class X>
template<class Y>
template<class Z>
template<class T>
void A<X>::B<Y>::C<Z>::foo()
{
   cout << "A<X>::B<Y>::C<Z>::foo()" << endl;
};
 
int main( void )
{
   A<int>::B<double>::C<char> c;
   c.foo<int>();
   return 0;
}