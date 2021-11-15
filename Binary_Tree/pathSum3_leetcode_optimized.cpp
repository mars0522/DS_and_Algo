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

    void fun(TreeNode* root, int sum, int target, unordered_map<int, int>& mp)
    {
        if (root == NULL) return;

        sum += root->val;

        if (mp.find(sum - target) != mp.end())
            total += mp[sum - target];

        mp[sum]++;

        fun(root->left, sum, target, mp);
        fun(root->right, sum, target, mp);

        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<int, int>mp;
        mp[0]++;

        fun(root, 0, targetSum, mp);

        return total;
    }
};