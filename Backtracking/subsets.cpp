class Solution {
public:

    void fun(vector<int>& nums, vector<int>&v, int i, vector<vector<int>>& res)
    {
        if (i == nums.size())
        {
            res.push_back(v);
            return;
        }

        else
        {
            v.push_back(nums[i]);
            fun(nums, v, i + 1, res);
            v.pop_back();

            fun(nums, v, i + 1, res);

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>>res;
        vector<int>v;

        fun(nums, v, 0, res);
        return res;
    }
};