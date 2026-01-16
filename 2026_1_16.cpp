#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
////int rand = 10;
//namespace r//命名空间域
//{
//	int rand = 2;
//}
//int a = 0;//全局域
//int main()//函数局部域
//{
//	//printf("%d", rand);//在库下rand为函数不能直接赋值 err
//
//	printf("%p\n", rand);//成功在namespace域里赋值输出地址
//	int a = 1;
//	printf("%d\n", a);//输出局部，邻近原则
//	printf("%d\n", ::a);//利用：：输出全局
//
//	printf("%d\n", r::rand);//::为域作用限定符，可以直接访问域中rand的值，不受库影响
//	return 0;
//}

#include<iostream>
using namespace std;
//int main()
//{
//	int a = 1;
//	double b = 0.1;
//	char c = 'z';
//	std::cout << a << " " << b << " " << endl;//cout在std域里
//	cout << a << " " << c << " " << endl;
//	//cin自动识别类型,并且不用取地址
//	cin >> a >> b >> c;
//	cout << a << " " << b << " " << c << endl;
//	return 0;
//}

//void Func(int a = 0)
//{
//	cout << a << endl;
//}
//int main()
//{
//	Func();     // 没有传参时，使⽤参数的默认值a = 0
//
//	Func(10);   // 传参时，使⽤指定的实参
//	return 0;
//}


// 全缺省
void Func1(int a = 10, int b = 20, int c = 30)
{
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl << endl;
}

//// 半缺省
//void Func2(int a, int b = 10, int c = 20)//必须从右向左缺
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl << endl;
//}
//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//
//	Func2(100);//func2不传会err因为a无默认值
//	Func2(100, 200);
//	Func2(100, 200, 300);
//	return 0;
//}


//函数重载（相同函数名称的使用）
//1、函数类型不同
//int Add(int a, int b)
//{
//	return a + b;
//}
//double Add(double a, double b)
//{
//	return a + b;
//}
//// 2、参数个数不同
//void f()
//{
//	cout << "f()" << endl;
//}
//void f(int a)
//{
//	cout << "f(int a)" << endl;
//}
//// 3、参数类型顺序不同
//void f(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void f(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}
//
//int main()
//{
//	int a =Add(1, 2);
//	double b = Add(1.2, 2.1);
//	cout << a << " " << b << endl;
//
//	f();
//	f(10);
//	f(10, 'a');
//	f('a', 10);
//
//	return 0;
//}



int main()
{
	int a = 0;
	// 引⽤：b和c是a的别名
	int& b = a;
	int& c = a;
	// 也可以给别名b取别名，d相当于还是a的别名
	int& d = b;++d;
	// 这⾥取地址是⼀样的
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;
	return 0;
}




