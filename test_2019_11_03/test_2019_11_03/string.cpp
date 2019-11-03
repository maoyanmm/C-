#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
#include<string>
//#include<cstring>
//#include<string.h>

int StrToInt(string str) {
	int sum = 0;
	int tmp = 0;
	int flag = 1;
	int i = 0;
	if (str[0] == '-')
	{
		flag = -1;
		++i;
	}
	else if (str[0] == '+')
	{
		flag = 1;
		++i;
	}
	while (i < str.size())
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return 0;
		}
		tmp = str[i] - '0';
		sum = sum * 10 + tmp;
		++i;
	}

void Stringtest()
{
	/*std::string s("helloc");
	cout << s << endl;*/
	string s1("hello");
	string s2(s1);
	string s3("nihao");
	string::iterator sit = s1.begin();
	int tmp = '1';
	cout << tmp << endl;
	
	//char* c = new char[20];
	///*char c[20];*/
	//strcpy(c, s1.c_str());
	//cout << c << endl;
	//s1 = "1234";
	/*cout << c << endl;*/
	/*cout << s1 << endl;
	swap(s1, s3);
	cout << s1 << endl;*/
/*
	s1.erase(1, 3);
	cout << s1 << endl;

	const char*c = s1.c_str();
	cout << c << endl;*/

	/*char a[20];
	strcpy(a, s1.c_str());*/
	/*cout << s1.size() << endl;*/
	//char* c;
	//c = s1.c_str();

	/*s1.push_back('s');
	cout << s1 << endl;
	s1.pop_back();
	cout << s1 << endl;*/
	/*swap(s1, s3);
	cout << s1 << endl;*/
	

	/*for (int i = 0; i < s3.length(); ++i)
	{
		cout << s3[i];
	}
	cout << endl;
	cout << s3.size() << endl;
	cout << s3.length() << endl;
	for (auto& e : s3)
	{
		e = 's';
	}
	cout << endl << endl;
	cout << "s3" << ' ' << s3 << endl;
	cout << endl << endl;

	cout << "s1" << ' ' << s1 << endl;
	cout << "s2" << ' ' << s2 << endl;
	string::iterator begin = s1.begin();
	string::iterator end = s1.end();
	while (begin != end)
	{
		*begin = 'h';
		++begin;
	}
	cout << "s1" << ' ' << s1 << endl;*/

	/*cout << endl << endl;
	s3 += s1;
	s3 += s2;
	cout << "s3" << ' ' << s3 << endl;
	cout << endl << endl;*/

	/*cout << "s1.size()" << ' ' << s1.size() << endl;
	cout << "s1.capacity()" << ' ' << s1.capacity() << endl;
	s1.resize(2);
	cout << "s1" << ' ' << s1 << endl;*/

	/*cout << endl << endl;
	s3 += s1;
	s3 += s2;
	cout << "s3" << ' ' << s3 << endl;
	cout << endl << endl;*/

	/*cout << "s1.capacity()" << ' ' << s1.capacity() << endl;
	s1.reserve(100);
	cout << "s1.capacity()" << ' ' << s1.capacity() << endl;*/

	/*cout << endl << endl;
	s3 += s1;
	s3 += s2;
	cout << "s3" << ' ' << s3 << endl;
	cout << endl << endl;*/

	/*s1.resize(10);

	cout << endl << endl;
	s3 += s1;
	s3 += s2;
	cout << "s3" << ' ' << s3 << endl;
	cout << endl << endl;

	s1.reserve(30);
	cout << "s1.capacity()" << ' ' << s1.capacity() << endl;
	cout << endl;*/

	/*s3 += s1;
	cout << "s3" << ' ' << s3 << endl;
	s3 += s2;
	cout << "s3" << ' ' << s3 << endl;
	s3 += "gaga";
	cout << "s3" << ' ' << s3 << endl;*/
	/*string s1("hello");
	s1.reserve(100);
	s1.reserve(30);
	string s2("nihao");
	s1 += s2;
	cout << s1 << endl;*/
}

int main()
{
	Stringtest();
	system("pause");
	return 0;
}