#include<iostream>
#include<string>
using namespace std;

//int Rabit(int m)
//{
//	int a = 1;
//	int b = 1;
//	int c = a + b;
//	int month = m - 2;
//	if (m <= 2)
//	{
//		return 1;
//	}
//	while (month--)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//
//int main()
//{
//	int m;
//	string a, b;
//	getline(cin, a);
//	while (cin >> m)
//	{
//		int ret = Rabit(m);
//		cout << ret << endl;
//	}
//	return 0;
//}
//
//int main()
//{
//	int flag = true;
//	cout << flag << endl;
//	system("pause");
//	return 0;
//}



bool TongSymbol(string& a, string& b)
{
	size_t i = 0;
	size_t j = 0;
	while (j < b.size())
	{
		if (a[i] == b[j])
		{
			++i;
			++j;
		}
		/*else if (a[i] != b[j] && (a[i] != '?' || a[i] != '*'))
		{
			return false;
		}*/
		else if (a[i] == '?' && ((b[j] <= '9' && b[j] >= '0')
			|| (b[j] >= 'a' && b[j] <= 'z')
			|| (b[j] >= 'A' && b[j] <= 'Z')))
		{
			++i;
			++j;
		}
		else if (a[i] == '?' && (!((b[j] <= '9' && b[j] >= '0')
			|| (b[j] >= 'a' && b[j] <= 'z')
			|| (b[j] >= 'A' && b[j] <= 'Z'))))
		{
			return false;
		}
		else if (a[i] == '*')
		{
			if (i + 1 < a.size())
			{
				size_t tmpj = b.size() - 1;
				while (tmpj >= j)
				{
					if (a[i + 1] == b[tmpj])
					{
						for (int tmp = j; j < tmpj; ++j)
						{
							if (!((b[tmp] <= '9' && b[tmp] >= '0')
								|| (b[tmp] >= 'a' && b[tmp] <= 'z')
								|| (b[tmp] >= 'A' && b[tmp] <= 'Z')))
							{
								return false;
							}
						}
						j = tmpj + 1;
						i += 2;
						break;
					}
					else
					{
						--tmpj;
					}
				}
				if (tmpj < j)
				{
					return false;
				}
			}
			else
			{
				while (j < b.size())
				{
					if ((b[j] <= '9' && b[j] >= '0')
						|| (b[j] >= 'a' && b[j] <= 'z')
						|| (b[j] >= 'A' && b[j] <= 'Z'))
					{
						++j;
					}
					else
					{
						return false;
					}
				}
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string dest;
	string source;
	getline(cin, dest);
	getline(cin, source);
	bool flag = TongSymbol(dest, source);
	if (flag)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}