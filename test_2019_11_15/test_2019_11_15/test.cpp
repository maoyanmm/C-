#include<iostream>
using namespace std;
//�����ж������߷���m*n�����̵ı���
int Tiptip(int a, int b, int n, int m)
{
	if (a == n && b == m)//�ߵ�ʱ����1��һ���߷�
	{
		return 1;
	}
	if ((a >= 0 && a < n) && (b >= 0 && b < m))//��������������ߣ��ǾͶ��ֱ���
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
//����������������������������
class UnusualAdd {
public:
	int addAB(int A, int B) {
		if (B == 0)//�����λ��0����ֱ�ӷ��ض����Ƶ���ӵĽ��A
		{
			return A;
		}
		int sum = A ^ B;//��ʾû�н�λ�Ķ�������ӽ��
		int go = (A&B) << 1;//��ʾ��������ӽ�λ�Ľ��
		return addAB(sum, go);
	}
};
//��С������
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
	for (i = a; i <= a*b; ++i)//������ӣ��ҵ�������������������
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
	for (i = b; i > 0; --i)//��С������ʼ��0�ң��ҵ����Լ��
	{
		if (a % i == 0 && b % i == 0)
		{
			break;
		}
	}
	int ans = (a / i)*b;//��С������ = ��������ٳ������Լ��
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
	while (y)//շת�����
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