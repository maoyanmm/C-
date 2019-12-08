// write your code here cpp
#include<iostream>
using namespace std;
#include<string>

string Div(string& num)
{
	int carry = 0;
	string tmp;
	int i = 0;
	if (num[i] == '1')
	{
		carry = 5;
		i = 1;
	}
	for (; i < num.size(); ++i)
	{
		int sum = num[i] - '0';
		if (sum % 2 == 1)
		{
			sum = sum / 2 + carry;
			tmp.push_back(sum + '0');
			carry = 5;
		}
		else
		{
			sum = sum / 2 + carry;
			tmp.push_back(sum + '0');
			carry = 0;
		}
	}
	return tmp;
}

int main()
{
	string n;
	while (cin >> n)
	{
		if (n[0] == '0')
		{
			break;
		}
		int count = 1;
		string nums = Div(n);
		while (nums.size() > 1)
		{
			nums = Div(nums);
			++count;
		}
		int last = nums[0] - '0';
		while (last > 1)
		{
			last /= 2;
			++count;
		}
		cout << count << endl;
	}
	return 0;
}



// write your code here cpp
#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n && n)
	{
		int count = 0;
		while (n > 1)
		{
			if (n % 3 == 0)//如果正好分三份，那就取其中一个
			{
				n /= 3;
			}
			else//如果余1，那就取最坏的情况（最多的），也就是n/3+1;如果余2，也就是这三份：n/3+1 - n/3+1 - n/3；那就取最坏的情况（最多的），也就是n/3+1，有两个n/3+1，那就随便取一个
			{
				n = n / 3 + 1;
			}
			++count;
		}
		cout << count << endl;
	}
	return 0;
}