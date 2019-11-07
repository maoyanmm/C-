#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

class String
{
public:
	//String()
	//	:_str(new char[1])
	//{
	//	*_str = '\0';
	//}
	//String(char* str)
	//	:_str(new char[strlen(str)+1])
	//{
	//	strcpy(_str, str);
	//}
	//String(const char* str = "")
	//	:_str(new char[strlen(str)+1])
	//{
	//	strcpy(_str, str);
	//}
	///*String(const String& str)
	//	:_str(new char[strlen(str._str)+1])
	//{
	//	strcpy(_str, str._str);
	//}*/
	//String(const String& str)
	//	:_str(nullptr)
	//{
	//	String tmp(str._str);
	//	swap(_str, tmp._str); 
	//}

	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	/*String(const String& str)
		:_str(new char[strlen(str._str)+1])
	{
		strcpy(_str, str._str);
	}*/
	String(const String& str)
		:_str(nullptr)
	{
		String tmp(str._str);
		swap(_str, tmp._str);
	}
	String& operator=(String str)
	{
		swap(_str, str._str);
		return *this;
	}


private:
	char* _str;
};

#if 0
void Reverse(string& str, int begin, int end)
{
	while (begin < end)
	{
		char tmp = str[begin];
		str[begin] = str[end];
		str[end] = tmp;
		begin++;
		end--;
	}
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		Reverse(str, 0, str.size() - 1);
		int flag = 0;
		int i = 0;
		for (i = 0; i<str.size(); i++)
		{
			if (str[i] == ' ')
			{
				Reverse(str, flag, i - 1);
				flag = i + 1;
			}
		}
		Reverse(str, flag, i - 1);
		cout << str << endl;
	}
	return 0;
}
 
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int* arr = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		int fbig = 0;
		int fsmall = 0;
		int count = 0;
		int i = 1;
		while (i < n)
		{

			if (arr[i] > arr[i - 1])
			{
				fbig = 1;
				if (fbig == 1 && fsmall == 1)
				{
					count++;
					fbig = 0;
					fsmall = 0;
				}
			}
			else if (arr[i] < arr[i - 1])
			{
				fsmall = 1;
				if (fbig == 1 && fsmall == 1)
				{
					count++;
					fbig = 0;
					fsmall = 0;
				}
			}
			i++;
		}
		count++;
		cout << count << endl;
	}
	return 0;
}
#endif

int main()
{
	String s1;
	String s2(s1);
	String s3("hello");
	s1 = s3;
	system("pause");
	return 0;
}