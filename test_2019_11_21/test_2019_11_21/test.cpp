#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<list>
//计算日期到天数转换
int Getdays(int year, int month)
{
	int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = arr[month];
	if (month == 2)
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		++days;
	}
	return days;
}

int main()
{
	vector<int> v;
	int y, m, d;
	while (cin >> y >> m >> d)
	{
		int days = 0;
		while (m > 1)
		{
			m -= 1;
			days += Getdays(y, m);
		}
		days += d;
		cout << days << endl;
	}
	return 0;
}
//非递归二叉树的前序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> st;
		vector<int> v;
		int flag = 0;
		while (1)
		{
			if (root)
			{
				if (0 == flag)
				{
					v.push_back(root->val);
					st.push(root);
					root = root->left;
				}
				else if (1 == flag)
				{
					root = root->right;
					flag = 0;
				}
			}
			else
			{
				if (st.empty())
				{
					break;
				}
				root = st.top();
				st.pop();
				++flag;
			}
		}
		return v;
	}
};