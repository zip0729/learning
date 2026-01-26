#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//inline int Add(int x, int y)//inline直接展开在主函数,不建议使用在内容很多的函数中，
//                              //会导致可执行程序变大
//{
//	int ret = x + y;
//	return ret;
//}


//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//int main()
//{
//	/*int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;*/
//
//	f(0);
//	// 本想通过f(NULL)调⽤指针版本的f(int*)函数，但是由于NULL被定义成0，调⽤了f(intx)，因此与程序的初衷相悖。
//	f(NULL);//使用在指针中
//	f((int*)NULL);
//	// f((void*)NULL);
//	// 编译报错：error C2665 : “f”: 2个重载中没有⼀个可以转换所有参数类型
//	f(nullptr);
//	return 0;
//}

//类中既可以有变量也可以有函数，访问限定符：public，private，protected
// 如果没设定限定符，默认是私有的private
//在类中输入限定符后的作用域是到下一个限定符之前，要么就是到类结束
//class Date//class也可以被替代成struct
//{
//public:
//    //void Init(Date* const this,int year, int month, int day)this指针
//    void Init(int year, int month, int day)
//    {
//        _year = year;//所有都是由this访问的
//        _month = month;
//        _day = day;
//    }
//    //void Print(Date* const this)不可以直接写到实参形参里
//    void Print()
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;//所有都是由this访问的
//    }
//private:
//    // 为了区分成员变量，⼀般习惯上成员变量
//    // 会加⼀个特殊标识，如_或者m开头
//    //声明
//    int _year; // year_  m_year
//    int _month;
//    int _day;
//};
//int main()
//{
//    // Date类实例化出对象d1和d2Date d1;
//    Date d1,d2;
//    //d1.Init(&d1,2024, 3, 31);this指针让输出的结果不同，而不是成员变量
//    d1.Init(2024, 3, 31);
//    d1.Print();
//    d2.Init(2024, 7, 5);
//    d2.Print();
//    return 0;
//    //Date实例化d1和d2两个对象，d1和d2都有各⾃独⽴的成员变量
//    //year / _month / _day存储各⾃的数据，但是d1和d2的成员函数Init / Print指针却是⼀样的，存储在对象
//    //中就浪费了。如果⽤Date实例化100个对象，那么成员函数指针就重复存储100次，太浪费了。
//}

//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//class B
//{
//public:
//	void Print()
//	{
//		//...
//	}
//};
//class C
//{
//};
//int main()
//{
//	A a;
//	B b;
//	C c;
//	cout << sizeof(a) << endl;
//	cout << sizeof(b) << endl;
//	cout << sizeof(c) << endl;
//	return 0;
//}
////我们看到没有成员变量的B和C类对象的⼤⼩是1，为什么没有成员变量还要给1个
////字节呢？因为如果⼀个字节都不给，怎么表⽰对象存在过呢！所以这⾥给1字节，纯粹是为了
// 占位标识对象存在。

//六个默认成员函数
// 初始化和清理：构造函数初始化  析构函数清理
// 拷贝复制：    拷贝构造使用同类对象初始化创建对象 赋值重载主要是把一个对象赋值给另一个对象
// 取地址重载：  普通对象和const对象取地址

//一：构造函数
//  1. 函数名与类名相同。
//2. ⽆返回值。(返回值啥都不需要给，也不需要写void，不要纠结，C++规定如此)
//3. 对象实例化时系统会⾃动调⽤对应的构造函数。
//4. 构造函数可以重载。


//class Date
//{
//public:
//	// 1.⽆参构造函数
//	/*Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}*/
//	// 2.带参构造函数  不传实参就叫默认构造也就是其它两种是 此种不是
//
//		/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	// 3.全缺省构造函数   此三种只能存在一种
//
//		Date(int year = 1, int month = 1, int day = 1)
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		void Print()
//		{
//			cout << _year << "/" << _month << "/" << _day << endl;
//		}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;//相当于直接调用了date()初始化
//	d1.Print();
//	Date d2(2026, 1, 21);//带参的
//	d2.Print();
//	Date d3(2026);//全缺省缺哪个补哪个带参 爽之
//}


//二：析构函数：(后定义的先析构)
//1. 析构函数名是在类名前加上字符~。
//2. ⽆参数⽆返回值。(这⾥跟构造类似，也不需要加void)
//3. ⼀个类只能有⼀个析构函数。若未显式定义，系统会⾃动⽣成默认的析构函数。
//4. 对象⽣命周期结束时，系统会⾃动调⽤析构函数。

//typedef int STDataType;
//class Stack
//{
//public:
//	Stack(int n = 4)//此处不写=4会报错，默认构造函数必须接受一个带参
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//				return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//	//编译器默认⽣成MyQueue的析构函数调⽤了Stack的析构，释放的Stack内部的资源
//	// 显⽰写析构，也会⾃动调⽤Stack的析构
//    /*~MyQueue()
//	{}*/
//private:
//	Stack pushst;
//	Stack popst;
//};
//int main()
//{
//	Stack st;
//	MyQueue mq;
//	return 0;
//}

//三：拷贝构造函数
//1. 拷⻉构造函数是构造函数的⼀个重载。
//2. 拷⻉构造函数的第⼀个参数必须是类类型对象的引⽤，使⽤传值⽅式编译器直接报错，因为语法逻
//辑上会引发⽆穷递归调⽤。拷⻉构造函数也可以多个参数，但是第⼀个参数必须是类类型对象的引
//⽤，后⾯的参数必须有缺省值。
//3. C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥⾃定义类型传值传参和传值返
//回都会调⽤拷⻉构造完成。
//4.若未显式定义拷⻉构造，编译器会⽣成⾃动⽣成拷⻉构造函数。⾃动⽣成的拷⻉构造对内置类型成
//员变量会完成值拷⻉/浅拷⻉(⼀个字节⼀个字节的拷⻉)，对⾃定义类型成员变量会调⽤他的拷⻉构
//造。
//5.如果⼀个类显⽰实现了析构并释放资源，那么他就需要显⽰写拷⻉构造，否则就不需要。

//class Date
//{
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // 编译报错：error C2652 : “Date”:⾮法的复制构造函数:第⼀个参数不应是“Date”
//    //Date(Date d)
//    Date(const Date& d)
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//    Date(Date* d)//指针需要传地址，不符合直觉
//    {
//        _year = d->_year;
//        _month = d->_month;
//        _day = d->_day;
//    }
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//void Func1(Date d)//传值，需要调用拷贝构造
//{
//    cout << &d << endl;
//    d.Print();
//}
//// Date Func2()
//Date& Func2()
//{
//    Date tmp(2024, 7, 5);
//    tmp.Print();
//    return tmp;
//}
//int main()
//{
//    Date d1(2024, 7, 5);
//    // C++规定⾃定义类型对象进⾏拷⻉⾏为必须调⽤拷⻉构造，所以这⾥传值传参要调⽤拷⻉构造
//    // 所以这⾥的d1传值传参给d要调⽤拷⻉构造完成拷⻉，传引⽤传参可以较少这⾥的拷⻉
//    Func1(d1);
//    cout << &d1 << endl;
//    // 这⾥可以完成拷⻉，但是不是拷⻉构造，只是⼀个普通的构造，也就是上述指针
//    Date d2(&d1);
//    d1.Print();
//    d2.Print();
//    //这样写才是拷⻉构造，通过同类型的对象初始化构造，⽽不是指针
//    Date d3(d1);
//    d3.Print();
//    // 也可以这样写，这⾥也是拷⻉构造
//    Date d4 = d1;
//    d2.Print();
//
//    // Func2返回了⼀个局部对象tmp的引⽤作为返回值
//    // Func2函数结束，tmp对象就销毁了，相当于了⼀个野引⽤
//
//    Date ret = Func2();
//    ret.Print();
//
//    return 0;
//}   

//四：运算符重载:
//1.重载运算符函数的参数个数和该运算符作⽤的运算对象数量⼀样多。⼀元运算符有⼀个参数，⼆元
//运算符有两个参数，⼆元运算符的左侧运算对象传给第⼀个参数，右侧运算对象传给第⼆个参数。
//2.如果⼀个重载运算符函数是成员函数，则它的第⼀个运算对象默认传给隐式的this指针，因此运算
//符重载作为成员函数时，参数⽐运算对象少⼀个。

class Date
{
public:
    Date(int year = 1, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void Print()
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    bool operator==(const Date& d)
    {
        return _year == d._year
            && _month == d._month
            && _day == d._day;
    }
    Date& operator++()
    {
        cout << "前置++" << endl;
        //...
        return *this;
    }
    Date operator++(int)
    {
        Date tmp;
        cout << "后置++" << endl;
        //...
        return tmp;
    }
private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date d1(2024, 7, 5);
    Date d2(2024, 7, 6);
    // 运算符重载函数可以显⽰调⽤

    d1.operator==(d2);
    // 编译器会转换成d1.operator==(d2);
    d1 == d2;
    // 编译器会转换成d1.operator++();
    ++d1;
    // 编译器会转换成d1.operator++(0);
    d1++;
    return 0;
}