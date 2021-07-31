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

    bool is_greater(TreeNode* root, int data)
    {
        if (root == NULL) return true;
        else if (data > root->val)
        {
            return is_greater(root->left, data) and is_greater(root->right, data);
        }
        else
            return false;
    }


    bool is_smaller(TreeNode* root, int data)
    {
        if (root == NULL) return true;
        else if (data < root->val)
        {
            return is_smaller(root->left, data) and is_smaller(root->right, data);
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {

        if (root == NULL) return true;
        else
            return (is_greater(root->left, root->val) and is_smaller(root->right, root->val) and isValidBST(root->left) and isValidBST(root->right));

    }
};