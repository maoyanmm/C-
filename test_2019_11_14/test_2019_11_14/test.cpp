#include<iostream>
using namespace std;
#include<string>
bool dictionary(string& str1, string& str2)
{
	int i = 0;
	int flag = 0;
	while (i < str1.size() && i < str2.size())
	{
		if (str1[i] > str2[i])
		{
			return false;
		}
		else if (str1[i] < str2[i])
		{
			return true;
		}
		++i;
	}
	if (str1.size() <= str2.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Stringlong(string& str1, string& str2)
{
	if (str1.size() >= str2.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n;
	while (cin >> n)
	{
		string arr[n];
		int dic = 1;
		int lon = 1;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < n; ++i)
		{
			if (!dictionary(arr[i - 1], arr[i]))
			{
				dic = 0;
			}
		}
		for (int i = 1; i < n; ++i)
		{
			if (!Stringlong(arr[i - 1], arr[i]))
			{
				lon = 0;
			}
		}
		if (dic == 0 && lon == 0)
		{
			cout << "none" << endl;
		}
		else if (dic == 1 && lon == 0)
		{
			cout << "lexicographically" << endl;
		}
		else if (dic == 0 && lon == 1)
		{
			cout << "lengths" << endl;
		}
		else
		{
			cout << "both" << endl;
		}
	}
	return 0;
}