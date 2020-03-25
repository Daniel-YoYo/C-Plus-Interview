
#include <iostream>
using namespace std;


#include "windows.h"
#include "winbase.h"
#include <process.h>



class Singelton
{
private: //1构造函数私有化
	//C++的构造函数 不能保证是线程安全
	Singelton()
	{
		printf("Singelton begin\n");
		Sleep(1000);
		printf("Singelton end\n");
	}
public:  //2 提供全局访问点  
	static Singelton *GetSingelton()
	{
		//每一次GetSingelton时候，都需要判断single是否存在
		if (single == NULL)  
		{
			single = new Singelton; //线程1 线程2 线程3 都去调用了new Singelton 
		}
		return single; //
	}
private:
	static Singelton *single;
};

Singelton* Singelton::single = NULL;


void main()
{
	
	//只有我们调用GetSingelton时，类才会new出对象，（在new对象实例的时候做判断）===》比较懒 懒汉式
	//优点 
	//缺点
	Singelton *s1 = Singelton::GetSingelton();

	Singelton *s2 = Singelton::GetSingelton();
	if (s1 == s2)
	{
		cout<<"s1 == s2"<<endl;
	}
	else
	{
		cout<<"s1!=s2"<<endl;
	}

	cout<<"hello..."<<endl;
	system("pause");
	return ;
}