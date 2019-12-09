// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

void Exchange(char& c)
{
	if (c == ' ')
	{
		return;
	}
	else if (c <= 'E')
	{
		c = c + 21;
	}
	else
	{
		c = c - 5;
	}
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); ++i)
		{
			Exchange(str[i]);
		}
		cout << str << endl;
	}
	return 0;
}

// write your code here cpp
#include<iostream>
#include<math.h>
using namespace std;

bool Single(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(n); ++i)
		{
			if (n%i == 0)
			{
				if (i == sqrt(n))
				{
					if (Single(i))
					{
						++count;
						continue;
					}
				}
				if (Single(i))
				{
					++count;
				}
				if (Single(n / i))
				{
					++count;
				}
			}
		}
		if (Single(n))
		{
			count = 2;
		}
		cout << count << endl;
	}
	return 0;
}