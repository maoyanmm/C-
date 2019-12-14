/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		return max(TreeDepth(pRoot->left) + 1, TreeDepth(pRoot->right) + 1);
	}
};


/*
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
		{
			return 0;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		int depth = 0;
		while (!q.empty())
		{
			++depth;
			for (int i = 0; i < q.size(); ++i)
			{
				TreeNode* cur = q.front();
				q.pop();
				if (cur->left)
				{
					q.push(cur->left);
				}
				if (cur->right)
				{
					q.push(cur->right);
				}
			}
		}
		return depth;
	}
};


/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
		{
			return pHead2;
		}
		if (pHead2 == NULL)
		{
			return pHead1;
		}
		ListNode* ans = NULL;
		if (pHead1->val >= pHead2->val)
		{
			ans = pHead2;
		}
		else
		{
			ans = pHead1;
		}
		ListNode* next2 = pHead2;
		ListNode* front1 = NULL;
		while (next2)
		{
			pHead2 = next2;
			next2 = next2->next;
			while (pHead1 && (pHead2->val > pHead1->val))
			{
				if (front1 == NULL)
				{
					front1 = pHead1;
				}
				else
				{
					front1 = front1->next;
				}
				pHead1 = pHead1->next;
			}
			if (pHead1 == NULL)
			{
				front1->next = pHead2;
				break;
			}
			if (front1 == NULL)
			{
				pHead2->next = pHead1;
				front1 = pHead2;
			}
			else
			{
				front1->next = pHead2;
				pHead2->next = pHead1;
				front1 = pHead2;
			}
		}
		return ans;
	}
};