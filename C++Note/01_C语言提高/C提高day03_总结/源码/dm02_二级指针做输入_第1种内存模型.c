#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void main()
{
	int		i = 0, j = 0;
	int		num = 0;
	char	*tmp = NULL;

	char *myArray[] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};

	// 整个数组大小,存放4个指针(32字节)
	num = sizeof(myArray);
	// 单个数组元素大小,指针(8字节)
	int len1= sizeof(myArray[0]);
	printf("num:%d\tLen1:%d\n", num, len1 );
	num = num/len1;

	for (i=0; i<num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray+i) );
	}

	for (i=0; i<num; i++)
	{
		for (j=i; j<num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0 )
			{
				tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}

	for (i=0; i<num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray+i) );
	}

	printf("hello...\n");
	return ;
}


void printMyArray11(char **myArray, int num)
{
	int i = 0;
	for (i=0; i<num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray+i) );
	}
}

void sortMyArray11(char **myArray, int num)
{
	int i =0 , j = 0;
	char *tmp = NULL;

	for (i=0; i<num; i++)
	{
		for (j=i; j<num; j++)
		{
			if (strcmp(myArray[i], myArray[j]) > 0 )
			{
				tmp = myArray[i];  //ע��  ������������Ԫ�� ��������ָ���ֵ //�ı�ָ���ָ��
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void main211()
{
	int		i = 0, j = 0;
	int		num = 0;
	char	*tmp = NULL;
	//���� �����е�ÿһ��Ԫ����ָ�� ָ������
	char *myArray[] = {"aaaaaa", "ccccc", "bbbbbb", "111111"};

	//��ӡ
	num = sizeof(myArray)/sizeof(myArray[0]);

	printMyArray11(myArray, num);

	sortMyArray11(myArray, num);

	printMyArray11(myArray, num);

	printf("hello...\n");
	return ;
}