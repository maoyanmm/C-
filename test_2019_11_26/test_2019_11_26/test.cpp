#include<iostream>
using namespace std;
#include<string>
int main()
{
	/*int i = 3;
	printf("%d,%d",++i,++i);*/
	/*float a = 0;
	if (abs(a) <= 1e-15)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}*/
	const int a = 10;
	int* p = (int*)a;
	*p = 20;
	cout << a << endl << *p << endl;
	system("pause");
	return 0;
}

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			ans ^= nums[i];
		}
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (int i = 0; i < numRows; ++i)
		{
			vv[i].resize(i + 1);
			for (int j = 0; j < i + 1; ++j)
			{
				if (j == 0 || j == i)
				{
					vv[i][j] = 1;
				}
				else
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}
		return vv;
	}
};


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int slow = 0;
		int fast = 1;
		while (fast < nums.size())
		{
			if (nums[fast] != nums[slow])
			{
				++slow;
				nums[slow] = nums[fast];
				++fast;
			}
			else
			{
				++fast;
			}
		}
		nums.resize(slow + 1);
		return slow + 1;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int i = 0;
		int j = 1;
		for (i = 0, j = 1; j < nums.size(); i += 3, j += 3)
		{
			if (nums[i] != nums[j])
			{
				return nums[i];
			}
		}
		return nums[i];

	}
};