// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

	// memoization solution
	int fun(int n, vector<int>& dp)
	{
		if (n < 0) return INT_MAX;

		if (n == 0) return 0;

		if (dp[n] != -1) return dp[n];

		int ans = INT_MAX;

		for (int i = 1; i * i <= n ; i++)
		{
			ans = min(ans, fun(n - i * i, dp));
		}

		return dp[n] = 1 + ans;
	}
	int MinSquares(int n)
	{
		// Code here
		// vector<int>dp(n+1,-1);

		// return fun(n,dp);

		// Iterative .ie   tabular solution

		vector<int>dp(n + 1);

		dp[0] = 0;

		for (int i = 1; i <= n; i++)
		{
			int j = 1;
			int ans = INT_MAX;
			while (j * j <= i)
			{
				ans = min(ans, dp[i - j * j]);
				j++;
			}

			dp[i] = 1 + ans;
		}

		return dp[n];

	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends