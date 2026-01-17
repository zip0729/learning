#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
//void SLText01()
//{
//	SL sl;
//	SLinit(&sl);//注意取地址，因为是指针变量
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//	SLPushBack(&sl, 4);
//	/*SLPrint(&sl);
//	SLPopBack(&sl);
//	SLPrint(&sl);*/
//
//	SLPushFront(&sl, 5);
//	SLPrint(&sl);
//	SLPopFront(&sl);
//	SLPrint(&sl);
//	SLDestroy(&sl);
//}
void SLtext02()
{
	SL sl;
	SLinit(&sl);
	SLPushBack(&sl, 1);
	SLPushBack(&sl, 2);
	SLPushBack(&sl, 3);
	SLPushBack(&sl, 4);
	SLPrint(&sl);

	SLInsert(&sl,0,9);
	SLPrint(&sl);
	SLDestroy(&sl);
}
int main()
{
	/*SLText01();*/
	SLtext02();
	return 0;
}