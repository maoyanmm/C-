#define D_SCL_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<stack>

using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int flag = 0;
	int count = 1;
	for (size_t i = 0; i < str.size(); ++i)//ͳ��ָ��ĸ���
	{
		if (str[i] == ' ' && flag == 0)
		{
			++count;
		}
		else if (str[i] == '"' && flag == 0)//���flag==0��˵����һ������"��Ҳ����������
		{
			++count;
			flag = 1;
		}
		else if (str[i] == '"' && flag == 1)//���flag==1��˵���������ţ������flag
		{
			flag = 0;
		}
		else
		{
		}
	}
	cout << count << endl;
	flag = 0;
	for (size_t i = 0; i < str.size(); ++i)//չʾ����ָ��
	{
		if (str[i] == ' ' && flag == 0)//����пո����û�������ţ�˵�����µ�ָ��
		{
			cout << endl;
		}
		else if (str[i] == '"' && flag == 0)//��������Ŷ����������ţ�˵�����µ�ָ��
		{
			cout << endl;
			flag = 1;
		}
		else if (str[i] == '"' && flag == 1)
		{
			flag = 0;
		}
		else
		{
			cout << str[i];
		}
	}
	cout << endl;
	return 0;
}


#include<iostream>
#include<stack>
using namespace std;

int main()
{
	size_t a, b;
	while (cin >> a >> b)
	{
		stack<int> st;//a��ջ
		stack<int> sti;//a��Լ����ջ
		size_t count = 0;
		int tmpa = a;
		int i = tmpa - 1;
		st.push(tmpa);
		while (tmpa != b)
		{
			for (; i > 1; --i)
			{
				if (tmpa % i == 0)
				{
					if (tmpa + i <= b)//���Լ��+a��bС���͸���a��i�����Ұ���������ջ
					{
						sti.push(i);
						tmpa += i;
						i = tmpa - 1;
						st.push(tmpa);
						break;
					}
				}
			}
			if (1 == i)//���û�ҵ���ȡ��a��ջ��Ԫ�غ�Լ����ջ��Ԫ�أ�������i��ֵΪԼ��ջ��Ԫ�ص�ֵ-1��Ҳ���Ǵӱ����Լ��С1������ʼ��Լ��
			{
				if (st.empty())
				{
					break;
				}
				st.pop();
				if (st.empty())
				{
					break;
				}
				tmpa = st.top();
				if (sti.empty())
				{
					break;
				}
				i = sti.top() - 1;
				sti.pop();
			}
		}
		if (st.empty())
		{
			cout << -1 << endl;
			return 0;
		}
		int j = st.size();
		while (j--)//ջ���ж���Ԫ�أ����߼�����һ��ʼ����ԭ����aֵ�����������Ҫ-1
		{
			++count;
		}
		cout << count - 1 << endl;
	}
	return 0;
}

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() != popV.size())
		{
			return false;
		}
		stack<int> st;
		int i = 0;
		int j = 0;
		while (j < popV.size())
		{
			if (st.empty() || st.top() != popV[j])
			{
				if (i == pushV.size())
				{
					return false;
				}
				st.push(pushV[i]);
				++i;
			}
			else
			{
				st.pop();
				++j;
			}
		}
		return true;
	}
};

class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> st;
		for (const auto& e : tokens)
		{
			if (e == "+" || e == "-"
				|| e == "*" || e == "/")
			{
				int right = st.top();
				st.pop();
				int left = st.top();
				st.pop();
				switch (e[0])
				{
				case '+':
					st.push(left + right);
					break;
				case '-':
					st.push(left - right);
					break;
				case '*':
					st.push(left*right);
					break;
				case '/':
					st.push(left / right);
					break;
				default:
					break;
				}
			}
			else
			{
				st.push(stoi(e));
			}

		}
		return st.top();
	}
};

