#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"
LTNode* LTBuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->next = node->prev = node;
	return node;
}
void LTInit(LTNode** pphead)
{
	*pphead = LTBuyNode(-1);

}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;
	
	phead->prev->next = newnode;
	phead->prev = newnode;
	

}

void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;//哨兵节点的下一位也就是在单链表中的头结点
	while (pcur != phead)//不等于哨兵结点时一直遍历打印数据
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;

	phead->next->prev = newnode;
	phead->next = newnode;
}

//尾删
void LTPopBack(LTNode* phead)
{
	//条件是在只有哨兵结点时不能删除也就是在删除功能中不能指向自己
	assert(phead && phead->next != phead);
	LTNode* del = phead->prev;
	// phead del->prev  del  后面没了
	del->prev->next = phead;
	phead->prev = del->prev;

	free(del);
	del = NULL;
}	

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	//phead del del->next
	phead->next = del->next;
	del->next->prev = phead;

	free(del);
	del = NULL;
}

//查找
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* pcur = phead->next;
	while (pcur)
	{
		if (pcur->data == x) 
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);//不可直接调用尾插 没参数给他传
	//pos newnode pos->next
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	//pos->prev pos pose->next
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;

	free(pos);
	pos = NULL;
}

//销毁
void LTDestroy(LTNode* phead)//此方法也需要传二级指针，但是因为要保持一致性直接传然后在主函数里设定实参为null
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next; 
		free(pcur);
		pcur = next;
	}
	//此时pcur指向phead，而phead还没被销毁
	free(phead);
	phead = NULL;
}