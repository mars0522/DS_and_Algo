class Solution {
public:

    // Top Down approach
    int fun(vector<int>& dp, vector<int>& arr, int cp, int n)
    {
        if (cp >= n - 1)
            return 0;
        if (arr[cp] == 0)
            return INT_MAX;

        if (dp[cp] != 0)
            return dp[cp];

        int ans = INT_MAX;

        for (int i = 1; i <= arr[cp]; i++)
        {
            ans = min(ans, fun(dp, arr, cp + i, n));
        }

        if (ans == INT_MAX)
            return dp[cp] = ans;
        else
            return dp[cp] = ans + 1;


    }
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n);

        return fun(dp, nums, 0, n);


        // Bottom up Approach

//         int n= nums.size();

//         vector<int>dp(n,INT_MAX);

//         dp[n-1]=0;

//         for(int i=n-2;i>=0;i--)
//         {
//             int ans = INT_MAX;

//             if(nums[i]==0)
//                 continue;
//             else if(nums[i] >= n-1-i)
//                 dp[i]= 1;
//             else
//             {
//                 for(int j=1;j<= nums[i] and i+j<=n-1 ;j++)
//                 {
//                     if(i+j<= n-1)
//                         ans = min(ans,dp[i+j]);
//                 }

//                 if(ans == INT_MAX)
//                     dp[i]= ans;
//                 else
//                     dp[i]= ans+1;
//             }
//         }

//         return dp[0];
    }
};