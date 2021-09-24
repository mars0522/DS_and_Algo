// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.


    // memoization dp
    int fun(int w, int wt[], int val[], int n, vector<vector<int>>& dp)
    {
        if (w == 0 or n == 0) return 0;
        else if (dp[n - 1][w] != -1) return dp[n - 1][w];

        if (wt[n - 1] > w)
            return dp[n - 1][w] = fun(w, wt, val, n - 1, dp);
        else
        {
            int l = fun(w, wt, val, n - 1, dp);
            int r = val[n - 1] + fun(w - wt[n - 1], wt, val, n - 1, dp);

            return dp[n - 1][w] = max(l, r);
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        //  vector<vector<int>>dp(n+1, vector<int>(W+1,-1));
        //  return fun(W,wt,val,n,dp);

        vector<vector<int>>dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (j < wt[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }


        }
        return dp[n][W];


    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}  // } Driver Code Ends