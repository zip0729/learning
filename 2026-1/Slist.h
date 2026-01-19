#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;//指向下一个结构体的指针
}SLTNnde;

//打印
void SLTPrint(SLTNnde* phead);

//插入中要申请空间
SLTNnde* SLTBuyNode(SLDataType x);
//插入
void SLTPushBack(SLTNnde** pphead, SLDataType x);

void SLTPushFront(SLTNnde** pphead, SLDataType x);

//删除
void SLTPopBack(SLTNnde** pphead);

void SLTPopFront(SLTNnde** pphead);

//查找
SLTNnde* SLTFind(SLTNnde* phead, SLDataType x);//返回一个结点 看是否有值为x的结点

// 单链表在pos位置之前插入x
void SListInsertBefore(SLTNnde** pphead, SLTNnde* pos, SLDataType x);

// 单链表在pos位置之后插入x
void SListInsertAfter(SLTNnde* pos, SLDataType x);

//删除pos节点
void SListEraseBefore(SLTNnde** pphead, SLTNnde* pos);

void SListEraseBefore(SLTNnde* pos);