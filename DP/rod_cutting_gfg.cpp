// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    // Top Down Approach
    int fun(int price[], int n, vector<int>& dp)
    {
        if (n < 0) return INT_MIN;
        if (n == 0) return 0;
        if (dp[n] != 0) return dp[n];

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, price[i] + fun(price, n - (i + 1), dp));

        return dp[n] = ans;
    }
    int cutRod(int price[], int n) {
        //code here

        // Top Down approach

        // vector<int>dp(n+1);
        // return fun(price,n,dp);

        // Bottom up Approach

        vector<int>dp(n + 1);

        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int ans  = INT_MIN;

            for (int j = 0; j < i; j++)
            {
                int cut = j + 1;

                if (i - cut >= 0)
                    ans = max(ans, dp[i - cut] + price[j]);
            }

            dp[i] = ans;
        }

        return dp[n];

    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends