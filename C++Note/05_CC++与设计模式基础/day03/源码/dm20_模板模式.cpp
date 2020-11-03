/*
 * @Author: your name
 * @Date: 2020-03-25 15:52:50
 * @LastEditTime: 2020-09-21 13:20:20
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /C++/C++Note/05_CC++与设计模式基础/day03/源码/dm20_模板模式.cpp
 */
#include <iostream>
using namespace std;


class MakeCar
{
public:
	virtual void MakeHead() = 0;
	virtual void MakeBody() = 0;
	virtual void MakeTail() = 0;

public:
	void Make() //ģ�庯�� ��ҵ���߼�������
	{
		MakeTail();
		MakeBody();
		MakeHead();
	}
};

//
class Jeep : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "jeep head" << endl;
	}

	virtual void MakeBody()
	{
		cout << "jeep body" << endl;
	}

	virtual void MakeTail()
	{
		cout << "jeep tail" << endl;
	}
};

class Bus : public MakeCar
{
public:
	virtual void MakeHead()
	{
		cout << "Bus head" << endl;
	}

	virtual void MakeBody()
	{
		cout << "Bus body" << endl;
	}

	virtual void MakeTail()
	{
		cout << "Bus tail" << endl;
	}
};

void main()
{
	MakeCar *car = new Bus;
	car->Make();
	delete car;

	MakeCar *car2 = new Jeep;
	car2->Make();
	delete car2;

	
	cout<<"hello..."<<endl;
	system("pause");
	return ;
}