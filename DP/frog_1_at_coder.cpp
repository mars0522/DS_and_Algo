
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

long long fun(vector<long long>&dp, vector<long long>&v , int n, int i)
{
	if (i == n - 1) return 0;

	if (i >= n) return INT_MAX;

	if (dp[i] != 0) return dp[i];

	long long ans1, ans2;
	ans1 = ans2 = INT_MAX;

	ans1 = abs(v[i] - v[i + 1]) + fun(dp, v, n, i + 1);

	if (i + 2 <= n - 1)
		ans2 = abs(v[i] - v[i + 2]) + fun(dp, v, n, i + 2);

	return dp[i] = min(ans1, ans2);


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


	int n;
	cin >> n;

	vector<long long>v(n);
	vector<long long>dp(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];


	// cout << fun(dp, v, n, 0) << endl;


	// Bottom up Approach

	dp[0] = 0;
	dp[1] = abs(v[0] - v[1]);

	for (int i = 2; i < n; i++)
	{
		dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
	}

	cout << dp[n - 1] << endl;






}