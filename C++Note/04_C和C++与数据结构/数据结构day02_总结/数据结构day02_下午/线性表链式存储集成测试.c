#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "linklist.h"

typedef struct Teacher
{
	LinkListNode node; //��һ���� (��һ��Ԫ��)
	int age;
	char name[64];
}Teacher;

void main()
{
	int len = 0, ret = 0, i = 0;

	LinkList* list = NULL;

	Teacher  t1, t2, t3, t4, t5;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	t4.age = 34;
	t5.age = 35;

	list = LinkList_Create();
	if (list == NULL)
	{
		return ;
	}

	len = LinkList_Length(list);

	//������㷨�;���ҵ��ڵ�ķ���
	ret = LinkList_Insert(list, (LinkListNode*) (&t1), 0);
	ret = LinkList_Insert(list, (LinkListNode*) (&t2), 0);
	ret = LinkList_Insert(list, (LinkListNode*) (&t3), 0);
	ret = LinkList_Insert(list, (LinkListNode*) (&t4), 0);
	ret = LinkList_Insert(list, (LinkListNode*) (&t5), 0);

	//����

	for (i=0; i< LinkList_Length(list); i++)
	{
		Teacher *tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp == NULL)
		{
			return ;
		}
		printf("tmp->age:%d ", tmp->age);
	}

	//ɾ������
	while (LinkList_Length(list) > 0)
	{
		Teacher *tmp = (Teacher *)LinkList_Delete(list, 0);
		if (tmp == NULL)
		{
			return ;
		}
		printf("tmp->age:%d ", tmp->age);
	}

	LinkList_Destroy(list);

	system("pause");
	return ;
}