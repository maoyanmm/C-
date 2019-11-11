#include<iostream>
using namespace std;
#include<algorithm>
#include<string>
int main()//����һ��ʮ����������Ҫת���Ľ��ƣ����ת�������
{
	int m, n;
	while (cin >> m >> n)
	{
		string s, table("0123456789ABCDEF");
		int flag = 1;
		if (m < 0)//����Ǹ������ȱ��һ�£����Ұ����������
		{
			flag = -1;
			m = -m;
		}
		while (m)
		{
			s += table[m % n];//���ϵ�ģ��Ȼ��β��
			m /= n;
		}
		if (-1 == flag)
		{
			s += '-';
		}
		reverse(s.begin(), s.end());//��Ϊ��β�壬����Ҫ����һ��
		cout << s << endl;
	}

	return 0;
}

int Howmany(int h, int l)
{
	int arr1[4][4] = { { 1, 1, 0, 0 }, { 1, 1, 0, 0 }, { 0, 0, 1, 1 }, { 0, 0, 1, 1 } };//���ֲ�ͬ�Ĳ��÷�����4*4�ľ���������и���Ŀռ���ô����������4*4����Ϊ��4*4�Ĳ��÷������ظ���
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
	}//�����ַ�����ȡ���Ĳ��õ���ķ���
	return sum1 > sum2 ? sum1 : sum2;
}

int main()
{
	int l, h;
	while (cin >> l >> h)
	{
		if ((l > 4) && (h > 4))//������������ڲ��õ�4*4���ͱ��ֻ��һ�ߴ���4������
		{
			int x = l / 4;
			int y = h / 4;
			int sum = 0;
			sum += x * y * 8; //������ٸ�������ĵ�����
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
		if (str[i] == '+')//��ͷ�������ţ���++i�������·���
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
				int tmp = str[i] - '0';//�������ַ��������
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