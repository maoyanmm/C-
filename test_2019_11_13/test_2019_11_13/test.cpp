#include<iostream>
#include<string>
using namespace std;
#include<vector>

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		string tmp;
		int i = 0;
		while (i < n)
		{
			if (A[i] == '(')//�����( ����
			{
				tmp.insert(tmp.begin(), A[i]);
				++i;
			}
			else if (A[i] == ')')//�����)�򿴿�֮ǰ��ŵ��Ƿ��Ƕ�Ӧ�ģ����� ������һ������ɾ���������жϺ����
			{
				if (tmp.size() == 0)
				{
					return false;
				}
				if (tmp[tmp.size() - 1] != '(')
				{
					return false;
				}
				else
				{
					++i;
					tmp.erase(tmp.begin());
				}
			}
			else{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	int n;
	cin >> n;
	int a = 0;
	int b = 1;
	int c = a + b;

	while (1)
	{
		if (n == c)//�����Ⱦ����0
		{
			break;
		}
		else if (c > n)
		{
			break;
		}
		else//���C<N�ͼ�����
		{
			a = b;
			b = c;
			c = a + b;
		}
	}
	int ret = 0;
	if (n == c)
	{
		cout << ret << endl;
	}
	else
	{
		ret = (c - n) < (n - b) ? (c - n) : (n - b);//��n > cʱ����n�͵�ǰ��쳲��������Ĳ�ֵ  ��  n����һ��쳲����������еĲ�ֵ �ĸ�С��
		cout << ret << endl;
	}
	return 0;
}



#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int result = nums[0];
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum >= 0)
		{
			sum += nums[i];
		}
		else
		{
			sum = nums[i];
		}
		if (sum > result)
		{
			result = sum;
		}
	}
	cout << result << endl;
	return 0;
}