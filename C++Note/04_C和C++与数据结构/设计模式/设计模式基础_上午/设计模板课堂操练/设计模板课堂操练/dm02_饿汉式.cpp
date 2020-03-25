
#include <iostream>
using namespace std;


#include "windows.h"
#include "winbase.h"
#include <process.h>



class Singelton
{
private: //1���캯��˽�л�
	//C++�Ĺ��캯�� ���ܱ�֤���̰߳�ȫ
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
public:  //2 �ṩȫ�ַ��ʵ�  
	/*
	static Singelton *GetSingelton()
	{
		//ÿһ��GetSingeltonʱ�򣬶���Ҫ�ж�single�Ƿ����
		if (single == NULL)  
		{
			single = new Singelton; //�߳�1 �߳�2 �߳�3 ��ȥ������new Singelton 
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

	//ֻ�����ǵ���GetSingeltonʱ����Ż�new�����󣬣���new����ʵ����ʱ�����жϣ�===���Ƚ��� ����ʽ
	//�ŵ� 
	//ȱ��
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

	for (i=0; i<threadnum; i++)  //�������̵ȴ� �������߳��������
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
	printf("main \n");


	system("pause");
}