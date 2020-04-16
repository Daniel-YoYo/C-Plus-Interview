#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * getStr1()
{
	char *p1 = "abcdefg2";
	return p1;
}
char *getStr2()
{
	char *p2 = "abcdefg2";
	return p2;
}

void main()
{
	char *p1 = NULL;
	char *p2 = NULL;
	p1 = getStr1();
	p2 = getStr2();

	// 打印内存空间数据
	printf("p1:%s\tp2:%s \n", p1, p2);
	// 打印值(地址)
	printf("p1:%d\tp2:%d \n", p1, p2);

	printf("hello...\n");
	return ;
}