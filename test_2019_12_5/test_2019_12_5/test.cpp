//��̬��̨��
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
//�쵽������
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

//��̬�滮�ĺ���㷨
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



#include<iostream>
#include<vector>
using namespace std;
int row, col;
//�Թ�
//·��
//����·��

void Out_maze(vector<vector<int>>& maze, vector<vector<int>>& maze_tmp, vector<vector<int>>& maze_best, int i, int j)
{
	maze[i][j] = 1;
	maze_tmp.push_back({ i, j });
	if (i == row - 1 && j == col - 1)
	{
		if (maze_best.empty() || maze_tmp.size() < maze_best.size())
		{
			maze_best = maze_tmp;
		}
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//����Ͽ�����
	{
		Out_maze(maze, maze_tmp, maze_best, i - 1, j);
	}
	if (i + 1 < row && maze[i + 1][j] == 0)//����¿�����
	{
		Out_maze(maze, maze_tmp, maze_best, i + 1, j);
	}
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//����������
	{
		Out_maze(maze, maze_tmp, maze_best, i, j - 1);
	}
	if (j + 1 < col && maze[i][j + 1] == 0)//����ҿ�����
	{
		Out_maze(maze, maze_tmp, maze_best, i, j + 1);
	}
	maze[i][j] = 0;
	maze_tmp.pop_back();
}

int main()
{
	while (cin >> row >> col)
	{
		//�����Թ�
		vector<vector<int>> maze(row, vector<int>(col, 0));
		vector<vector<int>> maze_tmp;
		vector<vector<int>> maze_best;
		//maze_tmp.clear();
		//maze_best.clear();
		for (auto& i : maze)
		{
			for (auto& j : i)
			{
				cin >> j;
			}
		}
		Out_maze(maze, maze_tmp, maze_best, 0, 0);
		for (auto& i : maze_best)
		{
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}
	return 0;
}
