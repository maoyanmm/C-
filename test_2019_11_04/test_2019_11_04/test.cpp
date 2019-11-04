#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	string addStrings(string num1, string num2) {
		int sum1 = 0;
		int sum2 = 0;
		int tmp1 = 0;
		int tmp2 = 0;
		int sum;
		string s;
		int i = 0;
		while (i < num1.size())
		{
			tmp1 = num1[i] - '0';
			sum1 = sum1 * 10 + tmp1;
			i++;
		}
		i = 0;
		while (i < num2.size())
		{
			tmp2 = num2[i] - '0';
			sum2 = sum2 * 10 + tmp2;
			i++;
		}
		sum = sum1 + sum2;
		while (sum)
		{
			tmp1 = sum % 10;
			sum /= 10;
			s += tmp1 + '0';
		}
		return s;
	}
};
void test()
{
	string s;
	int a = 7;
	char c = '8';
	int b = c - '0';
	/*s.resize(a);*/
	s+= b + '0';
	cout << s << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}