#include "stdafx.h"

#include "windows.h"
#include "winbase.h"
#include <process.h>
#include "iostream"

#include <iostream>
using namespace std;

class Singelton
{
private:
	Singelton()
	{
		cout<<"Singelton���캯��begin"<<endl;
		Sleep(1000);
		cout<<"Singelton���캯��end"<<endl;
	}

public:
	static Singelton *getSingelton()
	{
		if (single == NULL) //��Ҫ�ж�
		{
			count ++; 
			single = new Singelton();
		}
		return single;
	}

	static Singelton *releaseSingelton()
	{
		if (single != NULL) //��Ҫ�ж�
		{
			delete single;
			single = NULL;
		}
		return single;
	}
	static void pirntS() //���Ժ���
	{
		cout<<"Singelton printS test"<<endl;
	}

private:
	static Singelton *single;
	static int count ;
};

//note ��̬���������ʼ��  //����ʽ
Singelton *Singelton::single = NULL;
int Singelton::count = 0;

void main11()
{
	Singelton *s1 = Singelton::getSingelton();
	Singelton *s2 = Singelton::getSingelton();
	if (s1 == s2)
	{
		cout<<"ok....equal"<<endl;
	}
	else
	{
		cout<<"not.equal"<<endl;
	}
	cout <<"hello...."<<endl;
	system("pause");
}

void MyThreadFunc (void *)
{
	//cout << "�����߳��� ...." << endl;
	cout << "�����߳��� ....\n";
	Singelton::getSingelton()->pirntS();
}
int _tmain(int argc, _TCHAR* argv[])
{
	//main11();
	HANDLE hThread[10];

	for (int i=0; i<3; i++)
	{
		hThread[i] = (HANDLE)_beginthread (MyThreadFunc, 0, NULL);
	}

	for (int i=0; i<3; i++)
	{
		WaitForSingleObject( hThread[i], INFINITE );	
	}
		
	cout << "hello" << endl;
	system("pause");
	return 0;
}

