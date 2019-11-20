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
	for (size_t i = 0; i < str.size(); ++i)//统计指令的个数
	{
		if (str[i] == ' ' && flag == 0)
		{
			++count;
		}
		else if (str[i] == '"' && flag == 0)//如果flag==0，说明第一次遇见"，也就是左引号
		{
			++count;
			flag = 1;
		}
		else if (str[i] == '"' && flag == 1)//如果flag==1，说明是右引号，则更新flag
		{
			flag = 0;
		}
		else
		{
		}
	}
	cout << count << endl;
	flag = 0;
	for (size_t i = 0; i < str.size(); ++i)//展示各个指令
	{
		if (str[i] == ' ' && flag == 0)//如果有空格而且没有左引号，说明有新的指令
		{
			cout << endl;
		}
		else if (str[i] == '"' && flag == 0)//如果有引号而且是左引号，说明有新的指令
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
		stack<int> st;//a的栈
		stack<int> sti;//a的约数的栈
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
					if (tmpa + i <= b)//如果约数+a比b小，就更新a、i、并且把这两个入栈
					{
						sti.push(i);
						tmpa += i;
						i = tmpa - 1;
						st.push(tmpa);
						break;
					}
				}
			}
			if (1 == i)//如果没找到：取出a的栈顶元素和约数的栈顶元素，并更新i的值为约数栈顶元素的值-1（也就是从比这个约数小1的数开始找约数
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
		while (j--)//栈里有多少元素，就走几步（一开始入了原来的a值，所以最后结果要-1
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

