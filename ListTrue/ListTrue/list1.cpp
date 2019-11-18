#include<iostream>
using namespace std;
#include"list1.h"

void test1()
{
	List<int> lst;
	List<int>::iterator it = lst.begin();
	lst.Insert(it, 4);
	lst.Insert(lst.begin(), 3);
	lst.Insert(lst.begin(), 2);
	lst.Insert(lst.begin(), 1);
	lst.Erase(lst.end());
}
int main()
{
	test1();
	return 0;
}