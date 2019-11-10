#include<iostream>
using namespace std;
#include<vector>


bool Isfu(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int sum = 0;
		if (Isfu(arr, n))
		{
			sum = arr[0];
			for (int i = 0; i < n; i++)
			{
				if (arr[i] > sum)
				{
					sum = arr[i];
				}
			}
		}
		else
		{
			sum = 0;
			int tmpsum = 0;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] >= 0)
				{
					tmpsum += arr[i];
				}
				else
				{
					if (tmpsum > sum)
					{
						sum = tmpsum;
					}
					tmpsum = 0;
				}
			}
			if (tmpsum > sum)
			{
				sum = tmpsum;
			}

		}
		cout << sum << endl;
	}
	system("pause");
	return 0;

}


bool Ishuiwen(string& str)
{
	if (str.size() == 0 || str.size() == 1)
	{
		return true;
	}
	int begin = 0;
	int end = str.size() - 1;
	while (begin < end)
	{
		if (str[begin] != str[end])
		{
			return false;
		}
		++begin;
		--end;
	}
	return true;
}

void Insert(string& a, string& b, int pos)
{
	int szb = b.size();
	int beginb = 0;
	auto begina = a.begin() + pos;
	while (beginb < b.size())
	{
		a.insert(begina, b[beginb]);
		++beginb;
		++begina;
	}
}

int main()
{
	string a, b;
	while (cin >> a >> b)
	{

		int count = 0;
		int pos = 0;
		while (pos <= a.size())
		{
			string c = a;
			Insert(c, b, pos);
			if (Ishuiwen(c))
			{
				++count;
			}
			++pos;
		}
		cout << count << endl;
	}
	return 0;
}