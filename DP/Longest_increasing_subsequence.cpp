// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
    //Function to find length of longest increasing subsequence.


    // Top Down approach
    int fun(int a[], int pre, int curr, int n, vector<vector<int>>& dp)
    {
        if (curr == n) return 0;

        if (pre != -1)
            if (dp[pre][curr] != 0) return dp[pre][curr];

        int op1 = 0;

        if (pre == -1 or a[pre] < a[curr])
        {
            op1 = 1 + fun(a, curr, curr + 1, n, dp);
        }

        int op2 = fun(a, pre, curr + 1, n, dp);

        if (pre != -1)
            dp[pre][curr] = max(op1, op2);

        return max(op1, op2);
    }
    int longestSubsequence(int n, int a[])
    {
        // your code here


        // Top Down approach
        //   vector<vector<int>>dp(n+1, vector<int>(n+1));
        //   return fun(a,-1,0,n,dp);



        // Bottom up approach

        vector<int>dp(n, 1);
        int len = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                    len = max(len, dp[i]);
                }

            }
        }

        return len;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends