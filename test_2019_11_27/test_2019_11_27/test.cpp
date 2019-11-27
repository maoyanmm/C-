#include<iostream>
#include<algorithm>
using namespace std;
#include<string>

int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != -1)
		{
			cout << "joker JOKER" << endl;
			break;
		}
		int flag = str.find('-');
		string card1 = str.substr(0, flag);
		string card2 = str.substr(flag + 1);
		string c1 = card1.substr(0, card1.find(' '));
		string c2 = card2.substr(0, card1.find(' '));
		int num1 = 0;
		int num2 = 0;
		for (auto& e : card1)
		{
			if (e == ' ')
			{
				++num1;
			}
		}
		for (auto& e : card2)
		{
			if (e == ' ')
			{
				++num2;
			}
		}
		if (num1 != num2)
		{
			if (num1 == 3)
			{
				cout << card1 << endl;
				break;
			}
			else if (num2 == 3)
			{
				cout << card2 << endl;
				break;
			}
			else
			{
				cout << "ERROR" << endl;
			}
		}
		else
		{
			string all("345678910JQKA2jokerJOKER");
			if (all.find(c1) > all.find(c2))
			{
				cout << card1 << endl;
			}
			else
			{
				cout << card2 << endl;
			}
		}
	}
	return 0;
}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		if (str1.size() == 0 || str2.size() == 0)
//		{
//			string str;
//			cout << str << endl;
//			break;
//		}
//		if (str1.size() > str2.size())
//		{
//			swap(str1, str2);
//		}
//		int max_count = 0;
//		int max_i = 0;
//		for (int i = 0; i < str1.size(); ++i)
//		{
//			int tmpi = i;
//			int tmp_count = 0;
//			for (int j = 0; j < str2.size(); ++j)
//			{
//				if (str1[tmpi] == str2[j])
//				{
//					int tmpj = j;
//					while (tmpj < str2.size() && str1[tmpi] == str2[tmpj])
//					{
//						++tmp_count;
//						++tmpi;
//						++tmpj;
//					}
//				}
//				if (tmp_count > max_count)
//				{
//					max_count = tmp_count;
//					max_i = i;
//				}
//			}
//		}
//		string str = str1.substr(max_i, max_i + max_count);
//		cout << str << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//#include<vector>
//
//int Bottle(int k)
//{
//	int b = k;
//	int count = 0;
//	while (b >= 3)
//	{
//		count += b / 3;
//		b = b / 3 + b % 3;
//	}
//	if (2 == b)
//	{
//		++count;
//	}
//	return count;
//}
//
//int main()
//{
//	vector<int> v;
//	v.resize(10);
//	int i = 0;
//	for (i = 0; i < 10; ++i)
//	{
//		cin >> v[i];
//		if (v[i] == 0)
//		{
//			break;
//		}
//	}
//	for (int j = 0; j < i; ++j)
//	{
//		cout << Bottle(v[j]) << endl;
//	}
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//#include<string>
//bool Match(const char* part, const char* str)
//{
//	if (*part == '\0' && *str == '\0')
//	{
//		return true;
//	}
//	if (*part == '\0' || *str == '\0')
//	{
//		return false;
//	}
//	if (*part == '?')
//	{
//		return Match(part + 1, str + 1);
//	}
//	else if (*part == '*')
//	{
//		return Match(part + 1, str) || Match(part + 1, str + 1) || Match(part, str + 1);
//	}
//	else if (*part == *str)
//	{
//		return Match(part + 1, str + 1);
//	}
//	else
//	{
//		return false;
//	}
//}
//int main()
//{
//	string str1, str2;
//	while (cin >> str1 >> str2)
//	{
//		if (Match(str1.c_str(), str2.c_str()))
//		{
//			cout << "true" << endl;
//		}
//		else
//		{
//			cout << "false" << endl;
//		}
//	}
//	return 0;
//}