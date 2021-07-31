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

    int max(int x, int y)
    {
        return x > y ? x : y;
    }
    int fun(TreeNode* root, int& d)
    {
        if (root == NULL)
            return -1;
        else
        {
            int l = fun(root->left, d);
            int r = fun(root->right, d);

            d = max(d, l + r + 2);

            return 1 + max(l, r);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;
        fun(root, d);
        return d;

    }
};