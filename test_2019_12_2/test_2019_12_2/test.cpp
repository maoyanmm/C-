#include<iostream>
#include<vector>
using namespace std;

class Bonus {
public:

	int Max(int a, int b)
	{
		if (a > b)
			return a;
		return b;
	}

	int GetMax(vector<vector<int>> board, int i, int j)
	{
		int money = board[i][j];
		if (i == 5 && j == 5)
		{
			return board[5][5];
		}
		if (i == 5)
		{
			return money + GetMax(board, i, j + 1);
		}
		if (j == 5)
		{
			return money + GetMax(board, i + 1, j);
		}
		return money + Max(GetMax(board, i, j + 1), GetMax(board, i + 1, j));
	}

	int getMost(vector<vector<int> > board) {
		// write code here
		int result = GetMax(board, 0, 0);
		return result;
	}
};

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		int i = 0;
		int j = 0;
		int start = 0;
		int maxlen = 0;
		int len1 = str1.size();
		int len2 = str2.size();
		vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; ++i)
		{
			for (j = 1; j <= len2; ++j)
			{
				if (str1[i - 1] == str2[j - 1])
				{
					vv[i][j] = vv[i - 1][j - 1] + 1;
				}
				if (maxlen < vv[i][j])
				{
					maxlen = vv[i][j];
					start = i - maxlen;
				}
			}
		}
		cout << str1.substr(start, maxlen) << endl;
	}
	return 0;
}