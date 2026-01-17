#pragma once
//静态顺序表
#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//struct SeqList
//{
//	int arr[N];
//	int size;//指存进的（有效数据的）个数
//};
typedef int SLDataType;//方便同义替换
typedef struct SeqList
{
	SLDataType* arr;//int 要改可创建typedef直接修改上面的
	int size;
	int capacity;//有多少是多少的空间大小
}SL;//SeqList别名SL

//初始化
void SLinit(SL* ps);

//打印
void SLPrint(SL* s);

//销毁
void SLDestroy(SL* ps);

//插入
void check(SL* ps);
void SLPushBack(SL* ps, SLDataType x);//尾差
void SLPushFront(SL* ps, SLDataType x);//前插

//删除
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//插入
void SLInsert(SL* ps,int pos, SLDataType x);

//删除指定数据
void SLErase(SL* ps, int pos);

//查找
int SLFind(SL* ps, SLDataType x);