#include<iostream>
#include<string>
using namespace std;
#include"list1.h"

void test1()
{
	List<int> lst;
	List<int>::iterator it = lst.begin();
	lst.Insert(it, 4);
	lst.Insert(lst.begin(), 3);
	lst.PushBack(5);
	lst.PushFront(2);
	lst.PushFront(1);
	lst.Erase(lst.end());
	List<int> lst2(lst);
	it = lst2.begin();
	while (it != lst2.end())
	{
		cout << *it << ' ';
		++it;
	}
}

void test2()
{
	string s("12345");
	string::iterator it2 = s.begin();
	List<int> lst(s.begin(), s.end());
	List<int>::iterator it = lst.begin();
	/*while (it != lst.end())
	{
	cout << it._node->_data << ' ';
	++it;
	}	*/
	lst.PrintList();
}

void test3()
{
	List<int> lst;
	lst.PushBack(1);
	lst.PushBack(2);
	lst.PushBack(3);
	lst.PushBack(4);
	lst.PushBack(5);
	lst.PopBack();
	List<int> lst2;
	lst2 = lst;
	lst2.PrintList();
}

void test4()
{
	int arr[] = { 5, 6, 7, 8 };
	List<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
	lst.PrintList();
}

struct Date
{
	Date(size_t year = 2000, size_t month = 1, size_t day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	size_t _year;
	size_t _month;
	size_t _day;
};

void test5()
{
	List<Date> lst;
	lst.PushBack(Date(1997, 4, 18));
	lst.PushBack(Date(1997, 9, 3));
	List<Date>::iterator it = lst.begin();
	while (it != lst.end())
	{
		//cout << (*it)._year << '-' << (*it)._month << '-' << (*it)._day << endl;
		cout << it->_year << '-' << (*it)._month << '-' << (*it)._day << endl;
		++it;
	}
}

int main()
{
	test5();
	system("pause");
	return 0;
}