#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int maxcount = 0;
		int flag = 0;
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		for (int i = 0; i < str1.size(); ++i)
		{
			for (int j = 0; j < str2.size(); ++j)
			{
				if (str1[i] == str2[j])
				{
					int tmpi = i;
					int tmpj = j;
					int count = 0;
					while (tmpi < str1.size() && tmpj < str2.size() && str1[tmpi] == str2[tmpj])
					{
						++count;
						++tmpi;
						++tmpj;
					}
					if (count > maxcount)
					{
						maxcount = count;
					}
					if (tmpi == str1.size())
					{
						flag = 1;
						break;
					}
				}
			}
			if (1 == flag)
			{
				break;
			}
		}
		cout << maxcount << endl;
	}
	return 0;
}