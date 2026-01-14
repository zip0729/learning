#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	printf("hello");
//	int a;
//	scanf("%d", &a);
//	printf("%d\n", a);
//	return 0;
//}
// 
// 
//int main()
//{
//	int arr[10] = {0};
//	int* p1 = &arr[0];
//	int* p2 = arr;//数组名为首元素（第一个元素）的地址
//	//例外：sizeof 整个数组的大小（字节）
//	// &数组名 整个数组的地址
//}

//int main()
//{
//	int arr[10] = { 0 };
//	//使用指针
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* p =arr;
//	//输入数组值
//	for (int i = 0; i < sz; i++)
//	{
//		scanf("%d", p + i);//与&arr[i]相同
//	}
//	//输出
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", *(p + i));//同理arr[i] p[i] *(arr+i)
//	}
//	return 0;
//}
// 
// 函数输出
//void Print(int arr[10], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//}
//void Print(int* p, int sz)
//{
//	for (int i = 0; i < sz; i++) 
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);//还没有传参求得的是数组长度
//	Print(arr,sz);//arr为数组首元素地址
//	return 0;
//}

//冒泡排序，不适合接近有序的数组，为了解决加一个flag为0是交换过
//一趟排一个数组中数字直到不比相邻数字大或小
//此为升序,则大放最后，不比任何数字小
//void bubble_sort(int arr[], int sz)
//{
//	for (int i = 0; i < sz - 1; i++)//一（i）趟解决一个数字，10（sz）个数字，解决9个，剩一个不动就可以
//	{
//		int flag = 1;//假设已经有序
//		for (int j = 0; j < sz - 1 - i; j++)//在一趟中数字比较的次数j
//		{
//			if (arr[j] > arr[j + 1])//如果比相邻大，交换
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)//没被交换，则退出循环
//		{
//			break;
//		}
//	}
//	
//}
//void Print(int arr[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz);
//	Print(arr, sz);
//	return 0;
//}


//指针数组
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };

	int* arr[] = { arr1,arr2,arr3 };
	//打印
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);//非二维数组，是指针运算
			//指*（*（arr+i）+j）
		}
		printf("\n");
	}
	return 0;
}