#include "SeqList.h"


template <typename T>
SeqList<T>::SeqList(int Capacity)
{
	//T *pArray;   //����
	//pArray = new char[10]; //char array[10]
	pArray = new T[Capacity];
	this->capacity = Capacity;
	this->len = 0;
}

template <typename T>
SeqList<T>::~SeqList(void)
{
	delete[] pArray;
	pArray = NULL;
	len = 0;
	capacity = 0;
}

template <typename T>
int SeqList<T>::getLen()
{
	return this->len;
}

template <typename T>
int SeqList<T>::getCapacity()
{
	return capacity;
}

template <typename T>
int SeqList<T>::insert(T  &t, int pos)
{
	int i = 0;
	if (pos <0)
	{
		return -1;
	}

	//1 Ԫ�غ���
	for(i=len; i>pos; i--)
	{
		pArray[i] = pArray[i-1];
	}

	pArray[i] = t;  //stlԪ�ر���ʱͨ�� ���ƵĻ���ʵ�ֵ�, �����Ҫ���Ը��� ����.
	this->len ++;
	return 0;
}

template <typename T>
int SeqList<T>::get(int pos, T &t)
{
	int i = 0;
	if ( pos <0)
	{
		return -1;
	}
	t = pArray[pos]; //
	return 0;
}

template <typename T>
int SeqList<T>::del(int pos, T &t)
{
	int i = 0;

	t = pArray[pos]; //����pos��λ��

	for (i=pos+1; i<len; i++)  //posλ�ú����Ԫ��ǰ��
	{
		pArray[i-1] = pArray[i];
	}
	len --;
	return 0;
}
