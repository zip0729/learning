#define _CRT_SECURE_NO_WARNINGS 1
#include"Slist.h"
//打印
void SLTPrint(SLTNnde* phead)
{
	SLTNnde* pcur = phead;
	while (pcur)
	{
		printf("->%d", pcur->data);
		pcur = pcur->next;//指向下一个地址
	}
	printf("->NULL\n");
}
//插入中要申请空间
SLTNnde* SLTBuyNode(SLDataType x)//给空间
{
	SLTNnde* newNode = (SLTNnde*)malloc(sizeof(SLTNnde));
	if (newNode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}
//尾插
void SLTPushBack(SLTNnde** pphead, SLDataType x)//调用函数需要传地址，
                                                //传的地址指向的还是一个指针，所以用二级指针
{
	assert(pphead);
	SLTNnde* newnode = SLTBuyNode(x);
	//空链表和非空链表
	if (*pphead == NULL)//指向第一个节点的指针
	{
		*pphead = newnode;
		return;
	}
	//找尾
	SLTNnde* ptail = *pphead;
	while (ptail->next != NULL)//当一个节点不指向null（指向null为最后一个结点）
	{
		ptail = ptail->next;
	}
	//ptail指向的就是尾节点
	ptail->next = newnode;
}
//头插
void SLTPushFront(SLTNnde** pphead, SLDataType x)
{
	SLTNnde* newnode = SLTBuyNode(x);
	newnode->next = *pphead;//将新节点的指针next指向原来的头结点
	*pphead = newnode;//将原来的头结点指向newnode成为新头
}
//尾删
void SLTPopBack(SLTNnde** pphead)
{
	assert(pphead && *pphead);
	//只有一个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	else
	{
		//有多个节点
		SLTNnde* ptail = *pphead;
		SLTNnde* prev = *pphead;
		while (ptail->next)
		{
			prev = ptail;//保证prev在ptail之前
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}
//头删
void SLTPopFront(SLTNnde** pphead)
{
	assert(pphead && *pphead);//链表不能为空
	SLTNnde* next = (*pphead)->next;//先将首节点指向第二个节点，意义为存储
	free(*pphead);
	*pphead = next;
}
//查找
SLTNnde* SLTFind(SLTNnde* phead, SLDataType x)
{
	SLTNnde* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x) 
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//pcur = NULL
	return NULL;
}
//在pos位置之前插入
void SListInsertBefore(SLTNnde** pphead, SLTNnde* pos, SLDataType x)
{
	assert(pphead && *pphead);//链表不能为空
	assert(pos);
	SLTNnde* newnode = SLTBuyNode(x);
	//如果pos==*pphead那么是头插
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNnde* prev = *pphead;
		while (prev->next != pos)//遍历直到prev在pos前一个
		{
			prev = prev->next;
		}
		newnode->next = pos;//改变指向
		prev->next = newnode;
	}
	
}
//在pos位置之后插入
void SListInsertAfter(SLTNnde* pos, SLDataType x)
{
	assert(pos);
	SLTNnde* newnode = SLTBuyNode(x);
	newnode->next = pos;//改变指向
	pos->next = newnode;
}

//在pos位置之前删除
void SListEraseBefore(SLTNnde** pphead, SLTNnde* pos)
{
	assert(pphead && *pphead);//链表不能为空
	assert(pos);
	//如果删除的是头结点
	if (pos == *pphead)
	{
		//SLTNnde* next = (*pphead)->next;//先将首节点指向第二个节点，意义为存储
		//free(*pphead);
		//*pphead = next;
		SLTPopFront(*pphead);
	}
	else
	{
		SLTNnde* prev = *pphead;
		while (prev->next != pos)//遍历直到prev在pos前一个
		{
			prev = prev->next;
		}
		prev->next = pos->next;//改变指向
		free(pos);
		pos = NULL;
	}
	
}
//在pos位置之后删除
void SListEraseAfter(SLTNnde* pos)
{
	assert(pos && pos->next);
	SLTNnde* del = pos->next;//存上
	//pos del del->next
	pos->next = del->next;
	free(del);
	del = NULL;
}

void SListDestory(SLTNnde** pphead)
{
	assert(pphead && *pphead);//链表不能为空
	SLTNnde* pcur = &pphead;
	while (pcur)
	{
		SLTNnde* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}