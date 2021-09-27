// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
	int minDifference(int arr[], int n)  {
		// Your code goes here

		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += arr[i];

		int dp[n + 2][sum + 2];
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

		for (int j = sum / 2; j >= 0; j--)
		{
			if (dp[n][j])
			{
				return abs(sum - 2 * j);
			}
		}


	}
};


// { Driver Code Starts.
int main()
{


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];



		Solution ob;
		cout << ob.minDifference(a, n) << "\n";

	}
	return 0;
}  // } Driver Code Ends