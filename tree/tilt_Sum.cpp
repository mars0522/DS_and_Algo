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
    int tilt_sum;
    int fun(TreeNode* root)
    {
        if (root == NULL) return 0;
        else
        {
            int ls = fun(root->left);
            int rs = fun(root->right);
            int ts = ls + rs + root->val;
            root->val = abs(ls - rs);
            tilt_sum += root->val;
            return ts;
        }
    }
    int findTilt(TreeNode* root) {
        tilt_sum = 0;
        fun(root);
        return tilt_sum;

    }
};