// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
	int fun(int index, int sum, int target, int arr[], int n, int dp[1000][1000])
	{
		if (sum > target) return 0;
		if (sum == target) return 1;
		if (index == n) return 0;
		if (dp[index][sum] != -1) return dp[index][sum];

		int l = fun(index + 1, sum + arr[index], target, arr, n, dp);
		int r = fun(index + 1, sum, target, arr, n, dp);

		return dp[index][sum] = (l + r) % 1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
		// Your code goes here
		int dp[1000][1000];
		memset(dp, -1, sizeof(dp));

		return fun(0, 0, sum, arr, n, dp);
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