class Solution {
public:
    int total = 1000;
    int fun(int index, int sum, int target, vector<int>& nums, int dp[][2002])
    {
        if (index == nums.size())
        {
            if (sum == target) return 1;
            else
                return 0;
        }
        if (dp[index][total + sum] != -1) return dp[index][total + sum];

        int l = fun(index + 1, sum + nums[index], target, nums, dp);
        int r = fun(index + 1, sum - nums[index], target, nums, dp);

        return dp[index][total + sum]  = l + r;
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int dp[22][2002];
        memset(dp, -1, sizeof(dp));

        return fun(0, 0, target, nums, dp);

    }
};