#include<iostream>
#include<map>
#include<ctime>

using namespace std;

void main()
{
	time_t t;
	srand((unsigned int)time(&t));
	int a[100] = { 0 };
	for (int i = 0; i < 100; i++)
	{
		a[i] = rand() % 100;
	}

	for (int i = 0; i < 100; i++)//��ӡ
	{
		cout << a[i] << "\t";
	}

	map<int, int> M;
	for (int i = 0; i < 100; i++)
	{
		pair<map<int, int>::iterator, bool> pairIt = M.insert(pair<int, int>(a[i], 1));
		if (pairIt.second != true)
		{
			M[a[i]]++;
		}
	}

	int max = 0;//�洢Ƶ��
	int n = 0;//�±�
	int data=0;//a[i]
	for (int i = 0; i < 100; i++)
	{
		if (M[a[i]]>max)
		{
			n = i;
			data = a[i];
			max = M[a[i]];
		}
	}

	cout << "���������ǣ�a[" << n << "]=" << data << "���������ִ�����" << max << endl;

	cin.get();
}
