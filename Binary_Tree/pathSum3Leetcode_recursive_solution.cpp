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

    int total = 0;
    void fun(TreeNode* root, int sum, int target)
    {
        if (root == NULL) return;

        sum += root->val;

        if (sum == target)
            total++;

        fun(root->left, sum, target);
        fun(root->right, sum, target);

    }

    int pathSum(TreeNode* root, int targetSum) {

        if (root == NULL) return 0;

        fun(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total;
    }
};