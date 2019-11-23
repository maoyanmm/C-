#include<iostream>
using namespace std;
#include<string>
#include<vector>

//完全数计算
bool gcdsum(int x)
{
	int sum = 0;
	for (int i = 1; i < x; ++i)
	{
		if (x % i == 0)
		{
			sum += i;
		}
	}
	if (sum == x)
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 1; i < n; ++i)
		{
			if (gcdsum(i))
			{
				++sum;
			}
		}
		cout << sum << endl;
	}
	return 0;
}