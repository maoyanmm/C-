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
			if (A[i] == '(')//如果是( 则存放
			{
				tmp.insert(tmp.begin(), A[i]);
				++i;
			}
			else if (A[i] == ')')//如果是)则看看之前存放的是否是对应的（，是 ，则将这一对括号删除，继续判断后面的
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
		if (n == c)//如果相等就输出0
		{
			break;
		}
		else if (c > n)
		{
			break;
		}
		else//如果C<N就继续走
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
		ret = (c - n) < (n - b) ? (c - n) : (n - b);//当n > c时，看n和当前的斐波那契数的差值  与  n和上一个斐波那契额数列的差值 哪个小。
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