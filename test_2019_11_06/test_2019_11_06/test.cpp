#include<string>
#include<iostream>
using namespace std;

void Sort(int arr[], int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int tmp = arr[i + gap];
			int flag = i;
			while (flag >= 0 && tmp > arr[flag])
			{
				arr[flag + gap] = arr[flag];
				flag -= gap;
			}
			arr[flag + gap] = tmp;
		}

	}
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		int sum = 0;
		int* arr = new int[3 * n];
		for (int i = 0; i < 3 * n; i++)
		{
			cin >> arr[i];
		}
		Sort(arr, 3 * n);
		for (int i = n; i < 2 * n; i++)
		{
			sum += arr[i];
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}


int main()
{
	string a;
	string b;
	while (cin >> a >> b)
	{
		int size = a.size();
		for (int i = 0; i < b.size(); i++)
		{
			int slow = 0;
			int fast = 0;
			int count = 0;
			while (fast < size)
			{
				while (a[fast] == b[i])
				{
					fast++;
				}
				a[slow] = a[fast];
				count++;
				slow++;
				fast++;
			}
			size -= count;
		}
		a.resize(size);
		cout << a << endl;
	}
	system("pause");
	return 0;
}


class Solution {
public:
	string addStrings(string num1, string num2) {
		int flag1 = num1.size() - 1;
		int flag2 = num2.size() - 1;
		string ans;
		int size = num1.size() > num2.size() ? num1.size() : num2.size();
		ans.reserve(size + 1);
		int ret = 0;
		while (flag1 >= 0 || flag2 >= 0)
		{
			int x1 = 0;
			int x2 = 0;
			if (flag1 >= 0)
			{
				x1 = num1[flag1--] - '0';
			}

			if (flag2 >= 0)
			{
				x2 = num2[flag2--] - '0';
			}
			int sum = x1 + x2 + ret;
			if (sum > 9)
			{
				ret = 1;
				sum -= 10;
			}
			else
			{
				ret = 0;
			}
			ans += sum + '0';
		}
		if (1 == ret)
		{
			ans += '1';
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}
};