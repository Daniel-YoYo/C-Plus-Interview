#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
"name1111"
"name2222"
"name3333"
*/

typedef struct Teacher
{
	//char student[10][30]
	char name[64];
	char *alisname;
	char **stuname; 
	int age ;
	int id;
}Teacher;

void printTeacher(Teacher *array, int num)
{
	int i = 0;

	for (i=0; i<num; i++)
	{
		printf("age:%d \n", array[i].age);
	}
}

void sortTeacer(Teacher *array, int num)
{
	int		i,j;
	Teacher tmp;

	for (i=0; i<num; i++)
	{
		for (j=i+1; j<num; j++)
		{
			if (array[i].age > array[j].age)
			{
				tmp = array[i];  //=号操作  赋值操作
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

Teacher * createTeacher01(int num)
{
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num); //	Teacher		Array[3]
	if (tmp == NULL)
	{
		return NULL;
	}
	return tmp; //

}

int createTeacher02(Teacher **pT, int num)
{
	int i = 0, j = 0;
	Teacher * tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher) * num); //	Teacher		Array[3]
	if (tmp == NULL)
	{
		return -1;
	}
	memset(tmp, 0, sizeof(Teacher) * num);

	for (i=0; i<num; i++)
	{
		char **p = NULL;

		//malloc一级指针
		tmp[i].alisname = (char *)malloc(60);

		//二级指针的第三种内存模型
		p = (char **)malloc(3 * sizeof(char *));  //打造二维内存
		for (j=0; j<3; j++)
		{
			p[j] = (char *)malloc(120);
		}
		tmp[i].stuname = p; //
	
	}

	*pT = tmp;  //二级指针 形参 去间接的修改 实参 的值 
	return 0; //
}

void FreeTeacher(Teacher *p, int num)
{
	int	i = 0, j = 0;
	if (p == NULL)
	{
		return;
	}
	for (i=0; i<num; i++)
	{
		//释放一级指针
		if (p[i].alisname != NULL)
		{
			free(p[i].alisname);
		}

		//释放二级指针
		if (p[i].stuname != NULL)
		{
			char **myp = p[i].stuname ;
			for (j=0; j<3; j++)
			{
				if (myp[j] != NULL)
				{
					free(myp[j]);
				}
			}
			free(myp);
			p[i].stuname = NULL;
		}
	}
	free(p);
}

void main()
{
	int			ret = 0;
	int			i = 0, j = 0;
	//Teacher		Array[3];  //在stack 分配内存
	int			num = 3;
	Teacher *pArray = NULL;
	ret = createTeacher02(&pArray, num);
	if (ret != 0)
	{
		printf("func createTeacher02() er:%d \n ", ret);
		return ;
	}

	for (i=0; i<num; i++)
	{
		printf("\nplease enter age:");
		scanf("%d", & (pArray[i].age) );

		//printf("\nplease enter name:");
		//scanf("%s",  pArray[i].name ); //向指针所指的内存空间copy数据

		printf("\nplease enter alias:");
		scanf("%s",  pArray[i].alisname );  //向指针所指的内存空间copy数据

		for (j=0; j<3; j++)
		{
			printf("please enter student name:");
			scanf("%s",pArray[i].stuname[j] );
		}
	}

	//打印老师年龄
	// 	for (i=0; i<num; i++)
	// 	{
	// 		printf("age:%d \n", Array[i].age);
	// 	}

	printTeacher(pArray, num);

	sortTeacer(pArray, num);

	printf("排序之后\n");

	printTeacher(pArray, num);

	FreeTeacher(pArray, num);

	printf("hello...\n");
	system("pause");
	return ;
}