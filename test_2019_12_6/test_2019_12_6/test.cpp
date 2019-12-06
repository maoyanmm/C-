#include<iostream>
#include<string>

//不用加减乘除做加法
class Solution {
public:
	int Add(int num1, int num2)
	{
		
		int sum = num1 ^ num2;
		int flag = ((num1&num2) << 1);
		while (flag)
		{
			int tmp_sum = sum;
			int tmp_flag = flag;
			sum = tmp_flag^tmp_sum;
			flag = ((tmp_sum&tmp_flag) << 1);
		}
		return sum;
		
	}
};
//判断三角形

#include<iostream>
#include<string>
using namespace std;

void Reverse(string& str)
{
	int i = 0;
	int j = str.size() - 1;
	while (i < j)
	{
		swap(str[i], str[j]);
		++i;
		--j;
	}
}

string Add(string a, string b)
{
	if (a.size() > b.size())
	{
		swap(a, b);
	}
	int lena = a.size();
	int lenb = b.size();
	string ans;
	ans.resize(lenb + 1);
	int sum = 0;
	int flag = 0;
	int i = lena - 1;
	int j = lenb - 1;
	int k = 0;
	for (; i >= 0; --i, --j, ++k)
	{
		sum = (a[i] - '0') + (b[j] - '0') + flag;
		if (sum > 9)
		{
			flag = 1;
			sum -= 10;
		}
		else
		{
			flag = 0;
		}
		ans[k] = sum + '0';
	}
	for (; j >= 0; --j, ++k)
	{
		sum = (b[j] - '0') + flag;
		if (sum > 9)
		{
			flag = 1;
			sum -= 10;
		}
		else
		{
			flag = 0;
		}
		ans[k] = sum + '0';
	}
	if (1 == flag)
	{
		ans[lenb] = '1';
	}
	else
	{
		ans.resize(lenb);
	}
	Reverse(ans);
	return ans;
}

bool Compare(string a, string b)
{
	int lenb = b.size();
	int lena = a.size();
	if (lena > lenb)
	{
		return true;
	}
	else if (lena < lenb)
	{
		return false;
	}
	for (int i = 0; i < lena; ++i)
	{
		if (a[i] > b[i])
		{
			return true;
		}
		else if (a[i] < b[i])
		{
			return false;
		}
	}
	return false;
}

int main()
{
	string a, b, c;
	while (cin >> a >> b >> c)
	{

		string ab = Add(a, b);
		string bc = Add(b, c);
		string ac = Add(a, c);
		if (a.empty() || a.empty() || a.empty())
		{
			cout << "No" << endl;
		}
		else if (Compare(ab, c) && Compare(bc, a) && Compare(ac, b))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}