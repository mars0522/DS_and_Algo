// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

int dp[100002][102];
class Solution {
public:
    bool fun(int arr[], int n, int sum)
    {
        if (sum < 0  or n == 0 and sum) return false;
        else if (sum == 0) return true;
        if (dp[sum][n] != -1) return dp[sum][n];
        else
        {
            return dp[sum][n] = fun(arr, n - 1, sum) or fun(arr, n - 1, sum - arr[n - 1]);
        }
    }
    bool isSubsetSum(int n, int arr[], int sum) {
        // code here

        // recursive
        //  memset(dp,-1,sizeof(dp));
        //   return fun(arr,n,sum);

        // iterative

        int dp[n + 1][sum + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
            }
        }

        dp[1][arr[0]] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (j < arr[i - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                {
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[n][sum];

    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> sum;

        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0;
}
// } Driver Code Ends