#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"
void text02()
{
	SLTNnde* plist = NULL;//初始化plist
	SLTPushBack(&plist, 1);        //*plist    节点                       对应形参   **pphead
	SLTPushBack(&plist, 2);        //plist     指向第一个节点的指针                  *pphead
	SLTPushBack(&plist, 3);        //&plist    指向第一个节点的指针的地址            pphead
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	/*SLTPopBack(&plist);
	SLTPrint(plist);*/
	/*SLTPopFront(&plist);
	SLTPrint(plist);*/
	SLTNnde* find = SLTFind(plist, 1);
	SListInsertBefore(&plist, find, 11);
	SLTPrint(plist);
	/*if (find == NULL)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了");
	}*/
}
int main()
{
	text02();
	return 0;
}