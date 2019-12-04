// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		int result = 0;
		for (auto& e : str)
		{
			result += e - '0';
		}
		while (result / 10)
		{
			int tmp = 0;
			while (result)
			{
				tmp += result % 10;
				result /= 10;
			}
			result = tmp;
		}
		cout << result << endl;
	}
	return 0;
}