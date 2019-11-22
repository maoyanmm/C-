#include<iostream>
using namespace std;
#include<vector>
////计算整数中的二进制1的个数
//int main()
//{
//	int a;
//	while (cin >> a)
//	{
//		int count = 0;
//		if (a < 0)
//		{
//			++count;
//			a *= -1;
//		}
//		while (a != 0)
//		{
//			a = a&(a - 1);
//			++count;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
////二叉树的前序遍历的另一种方法
///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//* };
//*/
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root)
//	{
//		stack<TreeNode*> st;
//		vector<int> v;
//		TreeNode* p = root;
//		while (p || !st.empty())//p为空而且栈也为空则不进
//		{
//			while (p)//不断的访问左子树并且输入进数组
//			{
//				st.push(p);
//				v.push_back(p->val);
//				p = p->left;
//			}
//			p = st.top(); st.pop();
//			p = p->right;//继续进行以右节点为根的循环
//		}
//		return v;
//	}
//};
////递归的二叉树的前序遍历
//class Solution {
//public:
//
//	vector<int> preorderTraversal(TreeNode* root)
//	{
//		vector<int> v;
//		TreeNode* p = root;
//		x(v, p);
//		return v;
//	}
//	void x(vector<int>& v, TreeNode* root)
//	{
//		if (root)
//		{
//			v.push_back(root->val);
//			x(v, root->left);
//			x(v, root->right);
//		}
//		return;
//	}
//};
//
////非递归的二叉树中序遍历
///**
//* Definition for a binary tree node.
//* struct TreeNode {
//*     int val;
//*     TreeNode *left;
//*     TreeNode *right;
//*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//* };
//*/
//class Solution {
//public:
//	vector<int> inorderTraversal(TreeNode* root) {
//		stack<TreeNode*> st;
//		vector<int> ans;
//		TreeNode* p = root;
//		while (p || !st.empty())//p为空而且栈也为空则不进
//		{
//			while (p)//不断的访问左子树
//			{
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top(); st.pop();
//			ans.push_back(p->val);//将这个最左边的结点输入进数组
//			p = p->right;//继续进行以右节点为根的循环
//		}
//		return ans;
//	}
//};
//
////非递归二叉树的后序遍历
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		TreeNode* p = root;
//		vector<int> ans;
//		stack<TreeNode*> st;
//		TreeNode* tmp = NULL;//定义这个变量是为了让结点不再去访问已经访问过的右节点
//		while (p || !st.empty())
//		{
//			while (p)//不断的访问左子树
//			{
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top();
//			if (p->right == NULL || p->right == tmp)//如果没有右节点 或者 右节点已经访问过
//			{                                    //输入到数组、将标志更新、p置为空（为了不让p继续进行上面已经进行过的while
//				ans.push_back(p->val);
//				st.pop();
//				tmp = p;
//				p = NULL;
//			}
//			else
//			{
//				p = p->right;
//			}
//		}
//		return ans;
//	}
//};

void fun(int x)
{
	cout << x << endl;
}

int main()
{
	int i = 0;
	fun(i++);
	system("pause");
	cout << i << endl;
	return 0;
}