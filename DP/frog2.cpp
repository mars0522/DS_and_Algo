
#include<bits/stdc++.h>

#define vi vector<int>
#define pi pair<int,int>
#define pb push_back
#define f first
#define s second
#define ll long long

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


// Top Down approach

int fun(vector<int>& dp, vector<int>& arr, int i, int k, int n)
{
	if (i >= n) return INT_MAX;
	if (i == n - 1) return 0;

	if (dp[i] != -1) return dp[i];

	int ans = INT_MAX;


	for (int j = 1; j <= k; j++)
	{
		if (i + j < n)
			ans = min(ans, abs(arr[i] - arr[i + j]) + fun(dp, arr, i + j, k, n));
	}

	return dp[i] = ans;


}


int main()
{
	// for fast input output"
	ios::sync_with_stdio(0);
	cin.tie(0);

	// reading input from the file and displaying output to the file
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif



	int n , k;
	cin >> n >> k;
	vector<int>v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	vector<int>dp(n + 1);


	// Top Down approach

	// cout << fun(dp, v, 0, k, n) << endl;


	dp[n - 1] = 0;

	for (int i = n - 2; i >= 0; i--)
	{
		int ans = INT_MAX;
		for (int j = 1; j <= k; j++)
		{
			if (i + j < n)
				ans = min(ans, abs(v[i] - v[i + j]) + dp[i + j]);
		}

		dp[i] = ans;
	}


	cout << dp[0] << endl;

}