#include<iostream>
using namespace std;

class Solution {
public:
	bool isNumber(char& c)
	{
		return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
	}
	bool isPalindrome(string s) {
		if (s.empty())
		{
			return true;
		}
		for (auto& ch : s)
		{
			if (ch >= 'a')
			{
				ch -= 32;
			}
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isNumber(s[begin]))
			{
				++begin;
			}
			while (begin < end && !isNumber(s[end]))
			{
				--end;
			}
			if (s[begin] != s[end])
			{
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}
};

class Solution {
public:
	int firstUniqChar(string s) {
		int arr[26] = { 0 };
		int i = 0;
		while (i < s.size())
		{
			++arr[s[i] - 'a'];
			++i;
		}
		for (i = 0; i < s.size(); i++)
		{
			if (arr[s[i] - 'a'] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};

//class SUM
//{
//public:
//	class sum
//	{
//	public:
//		sum()
//		{
//			_count += _i;
//			++_i;
//		}
//	};
//
//	int forcount()
//	{
//		sum s[10];
//		return _count;
//	}
//	
//private:
//	static int _count;
//	static int _i;
//};
//int SUM::_count = 0;
//int SUM::_i = 1;

class SUM
{
public:
	class sum
	{
	public:
		int forcount()
		{
			SUM s[10];
			return _count;
		}
	};

	SUM()
	{
		_count += _i;
		++_i;
	}
private:
	static int _count;
	static int _i;
};
int SUM::_count = 0;
int SUM::_i = 1;


void test()
{
	/*SUM::sum s1;
	cout << s1.forcount() << endl;*/
	string s1("hello");
	auto begin = s1.begin();
	
}

int main()
{
	test();
	system("pause");
	return 0;
}