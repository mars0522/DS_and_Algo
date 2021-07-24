/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>res;
    void fun(TreeNode* root, int sum, vector<int>& v)
    {
        if (root == NULL)
            return;
        else if (root->left == NULL and root->right == NULL and sum - root->val == 0)
        {
            v.push_back(root->val);
            res.push_back(v);
            v.pop_back();
            return ;
        }

        else
        {
            v.push_back(root->val);
            fun(root->left, sum - root->val, v);
            fun(root->right, sum - root->val, v);
            v.pop_back();
            return ;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>v;
        fun(root, targetSum, v);
        return res;

    }
};