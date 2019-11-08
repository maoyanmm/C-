#include<iostream>
using namespace std;
#include<string>
#include<vector>

//class String
//{
//public:
//	String(int a , int b = 4, int c = 1)
//	{
//
//	}
//};
//
//int main()
//{
//	vector<int> aasdasd;
//	aasdasd.size
//}

class test
{
public:
	int forthemaxhalfnumber(vector <int> numbers)
	{
		int arr[10] = { 0 };
		int max = 0;
		int flag = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			arr[numbers[i]]++;
		}
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] > max)
			{
				flag = i;
				max == arr[i];
			}
		}
		return flag;
	}
};

int main()
{
	string str;
	string ans;
	cin >> str;
	int tip = 0;
	int maxsum = 0;
	int tmpsum = 0;
	int tmpflag = 0;
	int flag = 0;
	int begin = 0;
	int end = str.size();
	while (begin < end)
	{
		if (str[begin] <= '9' && str[begin] >= '0')
		{
			if (tip == 0)
			{
				tmpflag = begin;
			}
			begin++;
			tmpsum++;
			tip = 1;
		}
		else
		{
			if (tmpsum > maxsum)
			{
				maxsum = tmpsum;
				flag = tmpflag;
			}
			begin++;
			tip = 0;
			tmpsum = 0;
		}
	}
	if (tmpsum > maxsum)
	{
		maxsum = tmpsum;
		flag = tmpflag;
	}
	for (int i = flag; i < flag + maxsum; i++)
	{
		ans += str[i];
	}
	cout << ans << endl;
	system("pause");
	return 0;
}