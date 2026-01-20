#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
//定义结构
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;//后一
	struct ListNode* prev;//前一
}LTNode;

//初始化
LTNode* LTBuyNode(LTDataType x);
void LTInit(LTNode** pphead);//插入数据之前必须要初始化头结点(哨兵)

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);

//打印
void LTPrint(LTNode* phead);

//在pos位置之后插入数据
void LTInsert(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//销毁
void LTDestroy(LTNode* phead);