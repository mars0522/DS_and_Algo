class Solution {
public:

    // Top Down approach

//     int fun(vector<int>&dp, vector<int>& arr, int i, int n)
//     {
//         if(i>=n) return 0;
//         if(dp[i]!=0) return dp[i];
//        int  ans = max(arr[i]+ fun(dp,arr,i+2,n) , fun(dp,arr,i+1,n));

//         return dp[i]= ans;
//     }
    int rob(vector<int>& nums) {

        // Top Down approach
//         int sum=0;
//         for(auto i: nums)
//             sum+=i;
//         if(sum==0) return 0;

//         int n= nums.size();
//         vector<int>dp(n+1);

//         return fun(dp,nums,0,n);



        // Bottom up Approach


        int n = nums.size();
        vector<int>dp(n);

        if (nums.size() == 1)
            return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);

        return dp[n - 1];


    }
};