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