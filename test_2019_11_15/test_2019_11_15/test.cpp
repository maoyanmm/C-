#include<iostream>
using namespace std;
//计算有多少种走法走m*n的棋盘的边线
int Tiptip(int a, int b, int n, int m)
{
	if (a == n && b == m)//走到时返回1：一种走法
	{
		return 1;
	}
	if ((a >= 0 && a < n) && (b >= 0 && b < m))//如果两个都可以走，那就都分别走
	{
		return Tiptip(a + 1, b, n, m) + Tiptip(a, b + 1, n, m);
	}
	else if (b >= 0 && b < m)
	{
		return Tiptip(a, b + 1, n, m);
	}
	else
	{
		return Tiptip(a + 1, b, n, m);
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		int count = Tiptip(0, 0, n, m);
		cout << count << endl;
	}
	return 0;
}
//不用算数运算符计算两个数的相加
class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (B == 0)//如果进位是0，则直接返回二进制的相加的结果A
		{
			return A;
		}
		int sum = A ^ B;//表示没有进位的二进制相加结果
		int go = (A&B) << 1;//表示二进制相加进位的结果
		return addAB(sum, go);
	}
};
//最小公倍数
int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int i = a;
	for (i = a; i <= a*b; ++i)//不断相加，找到可以整除两个数的数
	{
		if (i % a == 0 && i % b == 0)
		{
			break;
		}
	}
	cout << i << endl;
	return 0;
}

int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int i = 0;
	for (i = b; i > 0; --i)//从小的数开始往0找，找到最大公约数
	{
		if (a % i == 0 && b % i == 0)
		{
			break;
		}
	}
	int ans = (a / i)*b;//最小公倍数 = 两数相乘再除以最大公约数
	cout << ans << endl;
	return 0;
}

int main()
{
	int a, b;
	cin >> a >> b;
	if (a < b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
	int x = a;
	int y = b;
	int z = 0;
	while (y)//辗转相除法
	{
		z = x % y;
		x = y;
		y = z;
	}
	/*int x = a;
	int y = b;
	int z = x % y;
	while (z)
	{
		x = y;
		y = z;
		z = x % y;
	}
	int ans = (a / y)*b;
	*/
	int ans = (a / x)*b;
	cout << ans << endl;
	return 0;
}