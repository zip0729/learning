#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int (*p)[10] = &arr;//数组的地址,p与[10]结合不了，所以为指针
//	//int* p[10] 是指针数组 p[10]为数组
//	return 0;
//}


//void print(int arr[3][5], int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print(int (*arr)[5],int r,int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(arr + i) + j));//arr[i][j]
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print(arr, 3, 5);//arr可传数组和指针（找首地址，也就是第一个一维数组）
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int(*p)(int, int) = &Add;//与函数的返回和参数类型一样//Add
//
//	int c = Add(2, 4);
//	printf("%d", c);
//	
//	int d = (*p)(2, 4);
//	printf("%d", d);
//
//	int e = p(2, 4);
//	printf("%d", e);
//
//	return 0;
//}

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int (*p)(int, int) = Add;//函数指针
	int (*parr[4])(int, int) = { Add,Sub,Mul,Div };//函数指针数组
	return 0;
}