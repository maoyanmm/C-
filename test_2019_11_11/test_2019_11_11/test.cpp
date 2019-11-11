#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
int main()//输入一个十进制数和想要转化的进制，输出转化后的数
{
	int m, n;
	while (cin >> m >> n)
	{
		string s, table("0123456789ABCDEF");
		int flag = 1;
		if (m < 0)//如果是负数就先标记一下，并且把它变成正数
		{
			flag = -1;
			m = -m;
		}
		while (m)
		{
			s += table[m % n];//不断的模，然后尾插
			m /= n;
		}
		if (-1 == flag)
		{
			s += '-';
		}
		reverse(s.begin(), s.end());//因为是尾插，所以要逆置一下
		cout << s << endl;
	}

	return 0;
}

int Howmany(int h, int l)
{
	int arr1[4][4] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 1, 1 }, { 0, 0, 1, 1 } };//两种不同的布置方案，4*4的矩阵，如果还有更大的空间那么继续引用这4*4，因为这4*4的布置方案是重复的
	int arr2[4][4] = { { 0, 0, 1, 1 }, { 0, 0, 1, 1 }, { 1, 1, 0, 0 }, { 1, 1, 0, 0 } };
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < l; ++j)
		{
			if (arr1[i][j] == 1)
			{
				++sum1;
			}
			else if (arr2[i][j] == 1)
			{
				++sum2;
			}
		}
	}//在两种方案中取最多的布置蛋糕的方案
	return sum1 > sum2 ? sum1 : sum2;
}

int main()
{
	int l, h;
	while (cin >> l >> h)
	{
		if ((l > 4) && (h > 4))//如果两个都大于布置的4*4，就变成只有一边大于4来计算
		{
			int x = l / 4;
			int y = h / 4;
			int sum = 0;
			sum += x * y * 8; //算出多少个矩阵里的蛋糕数
			int tmp = Howmany(h % 4, 4);
			sum += x * tmp;

			int n = h / 4;
			h = h % 4;
			int m1 = Howmany(4, l % 4);
			sum += m1 * n;
			int m2 = Howmany(h, l % 4);
			cout << sum + m2 << endl;
		}
		else if ((l > 4) && (h <= 4))
		{
			int n = l / 4;
			l = l % 4;
			int m1 = Howmany(h, 4);
			int sum = m1 * n;
			int m2 = Howmany(h, l);
			cout << sum + m2 << endl;
		}
		else if ((l <= 4) && (h > 4))
		{
			int n = h / 4;
			h = h % 4;
			int m1 = Howmany(4, l);
			int sum = m1 * n;
			int m2 = Howmany(h, l);
			cout << sum + m2 << endl;
		}
		else
		{
			cout << Howmany(h, l) << endl;
		}
	}
	return 0;
}

class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		int i = 0;
		int sum = 0;
		if (str.size() == 0)
		{
			return 0;
		}
		if (str[i] == '+')//开头是正负号，则++i，并更新符号
		{
			flag = 1;
			++i;
		}
		else if (str[i] == '-')
		{
			flag = -1;
			++i;
		}
		while (i < str.size())
		{
			if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			else
			{
				int tmp = str[i] - '0';//将数字字符变成整数
				sum = sum * 10 + tmp;
				++i;
			}
		}
		if (flag == -1)
		{
			sum = -sum;
		}
		return sum;
	}
};