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

    bool fun(TreeNode* root, long long min, long long max)
    {
        if (root == NULL)
            return true;
        else if (root->val > min and root->val < max)
        {
            return fun(root->left, min, root->val) and fun(root->right, root->val, max);
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {

        return fun(root, LLONG_MIN, LLONG_MAX);

    }
};