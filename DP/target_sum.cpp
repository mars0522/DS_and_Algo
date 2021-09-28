class Solution {
public:

    //  memoization solution
    int total = 1000;
    int fun(int index, int n, vector<int>& nums, int sum, int target, vector<vector<int>>& dp)
    {
        if (n == index)
        {
            if (sum == target) return 1;
            else
                return 0;
        }
        if (dp[index][sum + total] != -1) return dp[index][total + sum];

        int l = fun(index + 1, n, nums, sum + nums[index], target, dp);
        int r = fun(index + 1, n, nums, sum - nums[index], target, dp);

        return dp[index][total + sum] = l + r;

    }
    int findTargetSumWays(vector<int>& nums, int target) {


        // memoization solution
        int sum = 0;
        for (auto i : nums)
            sum += i;
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(total + sum + 1, -1));
        // memset(dp,0,sizeof(dp));

        return fun(0, n, nums, 0, target, dp);


        // more efficent iterative solution
        // it is equivalent to count no of ways of dividing an array into two subsets such that             their difference is the given number or no of subset having sum = (diff+ arr_sum)/2 //

//             if(nums.size()==1)
//             {
//                 if(nums[0]==target) return 1;
//                 else
//                     return 0;
//             }
//             int sum=0;
//             for(auto i: nums)
//                 sum+=i;

//             int n= nums.size();

//             int dp[n+1][sum+1];

//             memset(dp,0,sizeof(dp));

//             for(int i=0;i<=n;i++)
//                 dp[i][0]=1;
//             dp[1][nums[0]]=1;

//             target = (target+ sum)/2;

//         for(int i=2;i<=n;i++)
//         {
//             for(int j=1;j<=sum;j++)
//             {
//                 if(nums[i-1]> j)
//                     dp[i][j]= dp[i-1][j];
//                 else
//                     dp[i][j]= dp[i-1][j]+ dp[i-1][j- nums[i-1]];
//             }
//         }

//         return dp[n][target];
    }
};