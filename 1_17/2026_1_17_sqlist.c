#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
#include<stdio.h>
void SLinit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

void check(SL* ps)
{
    // 检查是否需要扩容
    if (ps->size == ps->capacity)
    {
        // 计算新容量：如果当前容量为0，初始化为4；否则翻倍
        int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;

        // 使用realloc重新分配内存
        // realloc的参数：
        // 1. 原内存块指针 (ps->arr)
        // 2. 新内存块大小 (newcapacity * sizeof(SLDataType))
        // 返回值：指向新内存块的指针，类型为void*
        // 将void*转换为SLDataType*类型
         SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));

        if (tmp == NULL)
        {
            perror("内存分配失败");
            exit(1);
        }
        // 分配成功，更新指针和容量
        ps->arr = tmp;          // arr指向新的内存块
        ps->capacity = newcapacity;  // 更新容量
    }
}
void SLPushBack(SL* ps, SLDataType x)
{
    assert(ps);//直接传空的解决方法
    check(ps);
    // 插入新元素
    ps->arr[ps->size] = x;// 在末尾插入
    ps->size++;
}
void SLPushFront(SL* ps, SLDataType x)
{
    assert(ps);
    check(ps);
    if (ps->arr == NULL)
    {
        printf("错误：arr 为 NULL\n");
        return;
    }
    //往后挪动
    for (int i = ps->size; i > 0; i--)
    {
        ps->arr[i] = ps->arr[i-1];
    }
    ps->arr[0] = x;
    ps->size++;
}
void SLPrint(SL* s)
{
    for (int i = 0; i < s->size; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void SLPopBack(SL* ps)
{
    assert(ps);
    assert(ps->size);//为0找不到-1下标 因为要找size-1下标
    ps->size--;
}


void SLPopFront(SL* ps)
{
    assert(ps);
    assert(ps->size);
    //往前挪动
    for (int i = 0; i < ps->size - 1; i++)
    {
        ps->arr[i] = ps->arr[i + 1];
    }
    ps->size--;
}

void SLInsert(SL* ps, int pos, SLDataType x)
{
    assert(ps);
    assert(pos >= 0&&pos<=ps->size);
    //插入需检查空间
    check(ps);
    for (int i = ps->size; i>pos; i--)
    {
        ps->arr[i] = ps->arr[i - 1];//最后应该为pos+1 = pos 空出pos 
    }
    ps->arr[pos] = x;//赋值
    ps->size++;
}

void SLErase(SL* ps, int pos)
{
    assert(ps);
    assert(pos >= 0 && pos < ps->size);//不可等于size，没数据
    for (int i = pos; i < ps->size - 1; i++)
    {
        ps->arr[i] = ps->arr[i + 1];
    }
    ps->size--;
}

int SLFind(SL* ps, SLDataType x)
{
    assert(ps);
    for (int i = 0; i < ps->size; i++)
    {
        if (ps->arr[i] = x)
        {
            return i;
        }
    }
    return -1;
}