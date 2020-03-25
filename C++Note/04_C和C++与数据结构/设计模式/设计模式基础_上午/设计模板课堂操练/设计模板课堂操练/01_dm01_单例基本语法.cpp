
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
		printf("Singelton begin\n");
		Sleep(1000);
		printf("Singelton end\n");
	}
public:  //2 �ṩȫ�ַ��ʵ�  
	static Singelton *GetSingelton()
	{
		//ÿһ��GetSingeltonʱ�򣬶���Ҫ�ж�single�Ƿ����
		if (single == NULL)  
		{
			single = new Singelton; //�߳�1 �߳�2 �߳�3 ��ȥ������new Singelton 
		}
		return single; //
	}
private:
	static Singelton *single;
};

Singelton* Singelton::single = NULL;


void main()
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