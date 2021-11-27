class Solution {
public:

    int fun(vector<int>& dp, int n)
    {
        if (n == 0 or n == 1) return 1;
        if (dp[n] != 0) return dp[n];

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            int x = fun(dp, n - i);
            int y = fun(dp, i - 1);

            ans += x * y;
        }

        dp[n] = ans;
        return dp[n] = ans;
    }
    int numTrees(int n) {

        vector<int>dp(n + 1);

        return fun(dp, n);


        // Bottom up Approach

//         vector<int>dp(n+1);
//         dp[0]=dp[1]=1;

//         for(int i=2;i<=n;i++)
//         {
//             int ans=0;
//             for(int j=1;j<=i;j++)
//                 ans+= dp[j-1]*dp[i-j];

//             dp[i]= ans;
//         }

//         return dp[n];
    }
};