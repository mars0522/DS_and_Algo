// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:

    // memoization code
    //int dp[1000][1000];
//  int fun(int index, int sum, int target,int arr[], int n)
//  {

//      if(sum > target) return 0;
//      if(sum==target) return 1;
//      if(index==n) return 0;

//      if(dp[index][sum]!=-1) return dp[index][sum];

//      int l = fun(index+1, sum+ arr[index], target,arr, n);
//      int r= fun(index+1, sum, target, arr, n);

//      return dp[index][sum]= (l+r)%1000000007;
//  }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        // memset(dp,-1,sizeof(dp));
        // return fun(0,0,sum,arr,n);


        // tabular approach

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
                if (arr[i - 1] <= j)
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % 1000000007;
                else
                    dp[i][j] = dp[i - 1][j];

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
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.perfectSum(a, n, sum) << "\n";

    }
    return 0;
}
// } Driver Code Ends