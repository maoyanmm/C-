#include<iostream>
using namespace std;
#include<vector>
////���������еĶ�����1�ĸ���
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
////��������ǰ���������һ�ַ���
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
//		while (p || !st.empty())//pΪ�ն���ջҲΪ���򲻽�
//		{
//			while (p)//���ϵķ����������������������
//			{
//				st.push(p);
//				v.push_back(p->val);
//				p = p->left;
//			}
//			p = st.top(); st.pop();
//			p = p->right;//�����������ҽڵ�Ϊ����ѭ��
//		}
//		return v;
//	}
//};
////�ݹ�Ķ�������ǰ�����
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
////�ǵݹ�Ķ������������
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
//		while (p || !st.empty())//pΪ�ն���ջҲΪ���򲻽�
//		{
//			while (p)//���ϵķ���������
//			{
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top(); st.pop();
//			ans.push_back(p->val);//���������ߵĽ�����������
//			p = p->right;//�����������ҽڵ�Ϊ����ѭ��
//		}
//		return ans;
//	}
//};
//
////�ǵݹ�������ĺ������
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		TreeNode* p = root;
//		vector<int> ans;
//		stack<TreeNode*> st;
//		TreeNode* tmp = NULL;//�������������Ϊ���ý�㲻��ȥ�����Ѿ����ʹ����ҽڵ�
//		while (p || !st.empty())
//		{
//			while (p)//���ϵķ���������
//			{
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top();
//			if (p->right == NULL || p->right == tmp)//���û���ҽڵ� ���� �ҽڵ��Ѿ����ʹ�
//			{                                    //���뵽���顢����־���¡�p��Ϊ�գ�Ϊ�˲���p�������������Ѿ����й���while
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