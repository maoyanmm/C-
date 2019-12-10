class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		vector<vector<int>> vv(triangle);
		vv[0][0] = triangle[0][0];
		for (int i = 1; i < triangle.size(); ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (0 == j)
				{
					vv[i][j] = vv[i - 1][j] + triangle[i][0];
				}
				else if (i == j)
				{
					vv[i][j] = vv[i - 1][j - 1] + triangle[i][i];
				}
				else
				{
					vv[i][j] = min(vv[i - 1][j - 1], vv[i - 1][j]) + triangle[i][j];
				}
			}
		}
		int len = triangle.size() - 1;
		int min = vv[len][0];
		for (int i = 1; i < len + 1; ++i)
		{
			if (vv[len][i] < min)
			{
				min = vv[len][i];
			}
		}
		return min;
	}
};



class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		vector<vector<int>> vv(triangle);
		vv[0][0] = triangle[0][0];
		int row = triangle.size();
		for (int i = row - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				vv[i][j] = min(vv[i + 1][j], vv[i + 1][j + 1]) + vv[i][j];
			}
		}
		return vv[0][0];
	}
};


class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.size();
		vector<bool> canbreak(len + 1, false);
		canbreak[0] = true;
		for (int i = 1; i <= len; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (canbreak[j])
				{
					if (dict.find(s.substr(j, i - j)) != dict.end())
					{
						canbreak[i] = true;
						break;
					}
				}
			}
		}
		return canbreak[len];
	}
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> path(m, vector<int>(n, 1));
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			}
		}
		return path[m - 1][n - 1];
	}
};