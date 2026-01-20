#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
void text01()
{
	LTNode* plist = NULL;
	LTInit(&plist);
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPrint(plist);
	LTNode* find = LTFind(plist, 3);
	/*if (find == NULL)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了");
	}*/
	/*LTPushFront(plist, 1);
	LTPushFront(plist, 1);*/
	LTErase(find);
	find = NULL;
	
}
int main()
{
	text01();
	return 0;
}