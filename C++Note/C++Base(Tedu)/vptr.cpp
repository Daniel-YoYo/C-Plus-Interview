/*
 * @Author: your name
 * @Date: 2020-07-14 17:51:29
 * @LastEditTime: 2020-07-14 18:21:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/C++Base(Tedu)/vptr.cpp
 */ 

// 虚继承中虚表指针,基类,公共基类内存分析
#include <iostream>
//using namespace std;


// 公共基类A
class A
{
public:
	unsigned long int dataA;
};
 
// 虚继承B
class B : virtual public A
{
public:
	unsigned long int dataB;
};
 
// 虚继承B
class C : virtual public A
{
public:
	unsigned long int dataC;
};

// 末端子类D
class D : public B, public C
{
public:
	unsigned long int dataD;
};

int main()
{
	D* d = new D;
	d->dataA = 10;
	d->dataB = 100;
	d->dataC = 1000;
	d->dataD = 10000;
 
	B* b = d; // 转化为基类B
	C* c = d; // 转化为基类C
	A* fromB = (B*) d;
	A* fromC = (C*) d;

	std::cout << "d address    : " << d << std::endl;
	std::cout << "b address    : " << b << std::endl;
	std::cout << "c address    : " << c << std::endl;
	std::cout << "fromB address: " << fromB << std::endl;
	std::cout << "fromC address: " << fromC << std::endl;
	std::cout << "Size : " << sizeof( *d ) << std::endl;
 
	std::cout << "vbptr address: " << ( unsigned long int * )d << std::endl;
	std::cout << "    [0] => " << *( unsigned long int * )(*( unsigned long int * )d) << std::endl;
	std::cout << "    [1] => " << *((( unsigned long int * )(*( unsigned long int * )d)) + 1)<< std::endl; // 偏移量20
	std::cout << "dataB value  : " << *(( unsigned long int * )d + 1) << std::endl;
	std::cout << "vbptr address: " << (( unsigned long int * )d + 2) << std::endl;
	std::cout << "    [0] => " << *( unsigned long int * )(*(( unsigned long int * )d + 2)) << std::endl;
	std::cout << "    [1] => " << *(( unsigned long int * )(*(( unsigned long int * )d + 2)) + 1) << std::endl; // 偏移量12
	std::cout << "dataC value  : " << *(( unsigned long int * )d + 3) << std::endl;
	std::cout << "dataD value  : " << *(( unsigned long int * )d + 4) << std::endl;
	std::cout << "dataA value  : " << *(( unsigned long int * )d + 5) << std::endl;
}