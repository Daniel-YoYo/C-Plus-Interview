
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
		m_num ++;
		printf("Singelton begin\n");
		Sleep(1000);
		printf("Singelton end\n");
	}
public:
	static void printS()
	{
		printf("m_num:%d \n", m_num);
	}
public:  //2 提供全局访问点  
	/*
	static Singelton *GetSingelton()
	{
		//每一次GetSingelton时候，都需要判断single是否存在
		if (single == NULL)  
		{
			single = new Singelton; //线程1 线程2 线程3 都去调用了new Singelton 
		}
		return single; //
	}
	*/
	static Singelton *GetSingelton()
	{
		return single; //
	}
		
private:
	static Singelton *single;
	static int m_num;
};

Singelton* Singelton::single = new Singelton;
int Singelton::m_num = 0;


void main22()
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

void threadFunc(void *p)
{
	DWORD id = GetCurrentThreadId();
	Singelton::GetSingelton()->printS();
	printf("id:%d\n", id);
	return;
}
void main()
{
	int i = 0;
	int threadnum = 3;
	HANDLE  hThread[100];
	//_CRTIMP uintptr_t __cdecl _beginthread (_In_ void (__cdecl * _StartAddress) (void *),
	//	_In_ unsigned _StackSize, _In_opt_ void * _ArgList);

	for (i=0; i<threadnum; i++)
	{
		hThread[i] = (HANDLE)_beginthread(threadFunc, 0, NULL);
	}

	for (i=0; i<threadnum; i++)  //让主进程等待 所有子线程运行完毕
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
	printf("main \n");


	system("pause");
}