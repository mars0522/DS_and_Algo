// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
int dp[102][100002];
class Solution {
public:


    // memoization solution
    bool fun(int n, int arr[], int sum)
    {
        if ((n == 0 and sum) or  sum < 0) return false;
        if (sum == 0) return true;

        if (dp[n][sum] != -1) return dp[n][sum];
        int l = fun(n - 1, arr, sum - arr[n - 1]);
        int r = fun(n - 1, arr, sum);

        return dp[n][sum] = l or r;
    }
    bool isSubsetSum(int n, int arr[], int sum) {
        // code here
        //memset(dp,-1,sizeof(dp));

        //return fun(N,arr,sum);

        // iterative solution

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
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
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