#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		int len1 = str1.size();
		int len2 = str2.size();
		int maxlen = 0;
		vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i < len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					vv[i][j] = vv[i - 1][j - 1] + 1;
				}
				if (vv[i][j] > maxlen)
				{
					maxlen = vv[i][j];
				}
			}
		}
		cout << maxlen << endl;
	}
	return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string str;
	while (cin >> n >> str)
	{
		int flag = 1;
		int first = 1;
		if (n <= 4)
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == 'U')
				{
					if (1 == flag)
					{
						flag = n;
					}
					else
					{
						--flag;
					}
				}
				else if (str[i] = 'D')
				{
					if (n == flag)
					{
						flag = 1;
					}
					else
					{
						++flag;
					}
				}
			}
			for (int i = 1; i < n; ++i)
			{
				cout << i << ' ';
			}
			cout << n << endl;
			cout << flag << endl;
		}
		else
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (str[i] == 'U')
				{
					if (flag == 1)
					{
						flag = n;
						first = n - 3;
					}
					else if (flag == first)
					{
						--flag;
						--first;
					}
					else
					{
						--flag;
					}
				}
				else
				{
					if (flag == n)
					{
						flag = 1;
						first = 1;
					}
					else if (flag == first + 3)
					{
						++flag;
						++first;
					}
					else
					{
						++flag;
					}
				}
			}
			for (int i = first; i < first + 3; ++i)
			{
				cout << i << ' ';
			}
			cout << first + 3 << endl;
			cout << flag << endl;
		}
	}
	return 0;
}