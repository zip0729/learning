#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//void func(int& x)//此处加&引用
//{
//	x++;//x改变就相当于a改变
//}
//int main()
//{
//	int a = 2;
//	func(a);//与c不同可以用引用 a传过去相当于直接改了名字变成x
//	// 引⽤：b和c是a的别名
//	int& b = a;
//	int& c = a;
//	// 也可以给别名b取别名，d相当于还是a的别名
//	int& d = b; ++d;
//	// 这⾥取地址是⼀样的
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	return 0;
//}


//int main()
//{
//	const int a = 10;//const只读不改
//	//int& ra = a;//err， 无const 又读又改 相当于权限放大 
//	const int& ra = a;//必须用const引用const
//
//	int b = 20;
//	const int& rb = b;//权限可以缩小，缩小的是引用rb的权限
//	b++;
//	//rb++;//不可修改
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	const int& ra = 30;
//	// 编译报错: “初始化” :⽆法从“int”转换为“int& ”
//	//int& rb = a * 3;
//	const int& rb = a * 3;
//
//
//	double d = 12.34;
//	// int& rd = d;
//	// 编译报错：“初始化” :⽆法从“double”转换为“int& ”
//	const int& rd = d;
//	return 0;
//}