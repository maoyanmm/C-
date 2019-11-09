#include<iostream>
using namespace std;
#include<string>
#include<math.h>

int Isprime(int x)
{
	if (x == 0 || x == 1 || x == 2)
	{
		return 1;
	}
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}

	}
	return 1;

}


int main()
{
	int a = 0;

	while (cin >> a)
	{
		int ret = Isprime(a);
		if (ret == 1)
			cout << "prime" << endl;
		else
			cout << "not prime" << endl;
	}

	return 0;
}

int main()
{
	int a = 0;
	while (cin >> a)
	{

		int b = a;
		int ans = 0;
		int count = 0;
		int x = 0;
		while (b)
		{
			b /= 10;
			count++;
		}
		b = a;
		while (b)
		{
			ans = ans * 10 + b % 10;
			b /= 10;
		}
		x = ans;
		while (x > 9)
		{
			cout << x % 10 << " ";
			x /= 10;
		}
		cout << x << endl;
		cout << ans << endl;
	}
	return 0;
}

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		int sum = 0;
		for (int i = x; i <= y; i++)
		{
			if (i % 3 == 1 && i % 5 == 3)
			{
				sum += i;
			}
		}
		cout << sum << endl;
	}
	return 0;
	
}


int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int i = -1;
		int* arr = new int[n];
		int nums = n;
		while (1)
		{
			int count = m;
			while (count)
			{
				i++;
				if (i == n)
				{
					i = 0;
					if (arr[i] != 1)
					{
						count--;
					}
				}
				else
				{
					if (arr[i] != 1)
					{
						count--;
					}
				}
			}

			arr[i] = 1;
			nums--;
			if (nums == 1)
			{
				break;
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (arr[j] != 1)
			{
				cout << j + 1 << endl;
			}
		}
	}
	return 0;
}//


int main()
{
	int a1, a2, a3, a4;
	int A, B, C;
	while (cin >> a1 >> a2 >> a3 >> a4)
	{
		if ((a1 + a3) / 2 != ((a1 + a2) + (a1 + a4)) / 2)
		{
			cout << "NO" << endl;
		}
		else
		{
			A = ((a1 + a2) + (a1 + a4)) / 2;
			B = a3 - A;
			C = a4 - B;
			cout << A << ' ' << B << ' ' << C << endl;
		}
	}
	return 0;
}