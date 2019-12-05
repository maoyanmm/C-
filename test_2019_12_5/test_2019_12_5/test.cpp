//变态跳台阶
class Solution {
public:
	int jumpFloorII(int number) {
		if (1 == number || 0 == number)
		{
			return 1;
		}
		else
		{
			return 2 * jumpFloorII(number - 1);
		}
	}
};
//快到碗里来
#include<iostream>
#include<string>
using namespace std;
#define pai2 6.28
int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		if (n > 2 * r*3.14)
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}

//动态规划的红包算法
class Bonus {
public:
	int getMost(vector<vector<int> > board) {
		// write code here
		int row = board.size();
		int col = board[0].size();
		vector<vector<int>> vv(row, vector<int>(col, 0));
		vv[0][0] = board[0][0];
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (0 == i && 0 == j)
				{
					continue;
				}
				if (0 == i)
				{
					vv[i][j] = vv[i][j - 1] + board[i][j];
				}
				else if (0 == j)
				{
					vv[i][j] = vv[i - 1][j] + board[i][j];
				}
				else
				{
					vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]) + board[i][j];
				}
			}
		}
		return vv[row - 1][col - 1];
	}
};