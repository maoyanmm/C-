#include<iostream>
using namespace std;
#include<math.h>

bool Isprimenum(int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
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
		int a = n / 2;
		int b = n / 2;
		while (a < n)
		{
			if (Isprimenum(a) && Isprimenum(b))
			{
				break;
			}
			else
			{
				++a;
				--b;
			}
		}
		cout << b << endl;
		cout << a << endl;
	}
	return 0;
}

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		int tmp = m << j;
		return tmp + n;
	}
};