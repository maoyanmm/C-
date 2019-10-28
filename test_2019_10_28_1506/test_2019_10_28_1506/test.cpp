#include<iostream>
using namespace std;

class A
{
public:
	A(int a = 1)
	:_a(a)
	{

	}
private:
	int _a;
};

class B
{
public:
	B(int x, int y)
		: _c(y)
		, _b(2)
	{

	}
private:
	A _a;
	const int _b;
	int& _c;
};

class C
{
public:
	C(int x )
		:_a(x)
		, _b(_a*2)
	{
	/*	_a = x;*/
		_b = _a * 2;
	}
	void Display()
	{
		cout << "_a = " << _a << "_b = " << _b << endl;
	}
	explicit C(int x = 1,int y = 2)
		:_a(x)
		, _b(_a * 2)
	{
		_b = _a * 2;
	}
private:
	int _b;
	int _a;
};

class Date
{
public:
	Date(int year, int month, int day)
	:_year(year)
	, _month(month)
	, _day(day)
	{

	}
private:
	int _year;
	int _month;
	int _day;
};

//class Num
//{
//public:
//	class num
//	{
//	public:
//		num()
//		{
//			_sum += _i;
//			++_i;
//		}
//	};
//	int sum()
//	{
//		num arr[6];
//		return _sum;
//	}
//private:
//	static int _sum;
//	static int _i;
//};
//int Num::_sum = 0;
//int Num::_i = 1;
/////////////////////////////
class num;
class Num
{
	friend class num;
public:
	int sum()
	{
		num arr[6];
		return _sum;
	}
private:
	static int _sum;
	static int _i;
};
int Num::_sum = 0;
int Num::_i = 1;

class num
{
public:
	num()
	{
		Num::_sum += Num::_i;
		++Num::_i;
	}
};

//class X;
//class Y
//{
//	friend class X;
//public:
//	int SUM()
//	{
//		X arr[5];
//		return _sum;
//	}
//private:
//	static int _i;
//	static int _sum;
//};
//int Y::_i = 1;
//int Y::_sum = 0;
//
//class X
//{
//public:
//	X()
//	:_x(1)
//	{
//		Y::_sum += Y::_i;
//		++Y::_i;
//	}
//private:
//	int _x;
//};

void test()
{
	/*B b1(1,2);*/
	/*C c1;
	c1.Display();
	c1 = 2;
	c1.Display();*/
	Num n1;
	cout << n1.sum() << endl;
	/*Y y1;
	cout << y1.SUM() << endl;*/
}

int main()
{
	test();
	system("pause");
	return 0;
}