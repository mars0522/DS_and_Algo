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

	vector<int>v;

	void fun(TreeNode* root, int d)
	{
		if (root == NULL or d < 0)
			return ;
		else if (d == 0)
			v.push_back(root->val);

		else {

			fun(root->left, d - 1);
			fun(root->right, d - 1);
		}
	}

	int fun2(TreeNode* root, int target, int d)
	{
		if (root == NULL)
			return -1;
		else if (root->val == target)
		{
			fun(root, d);
			return 0;
		}

		int dl = fun2(root->left, target, d);

		if (dl != -1)
		{
			if (1 + dl == d)
				v.push_back(root->val);
			else
				fun(root->right, d - dl - 2);

			return dl + 1;

		}

		int dr = fun2(root->right, target, d);

		if (dr != -1)
		{
			if (1 + dr == d)
				v.push_back(root->val);
			else
				fun(root->left, d - dr - 2);

			return dr + 1;

		}

		return -1;

	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

		fun2(root, target->val, k);
		vector<int>result = v;
		v.clear();
		return result;


	}
};