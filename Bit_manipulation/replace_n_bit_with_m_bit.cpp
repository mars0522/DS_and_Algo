
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

int clear_bits(int n, int i, int j)
{
	int a = (-1 << (j + 1));
	int b = (1 << i - 1);
	int mask = a | b;

	return (n & mask);
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

	int n, m, i, j;
	cin >> n >> m >> i >> j;

	int mask = clear_bits(n, i, j);
	cout << (mask | (m << i)) << endl;

}