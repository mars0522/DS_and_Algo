#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ff                    first
#define ss                    second
#define ll                    long long
#define pb                    push_back
#define mp                    make_pair
#define pii                   pair<int,int>
#define vi                    vector<int>
#define mii                   map<int,int>
#define pqb                   priority_queue<int>
#define pqs                   priority_queue<int,vi,greater<int>>
#define setbits(x)            __builtin_popcountll(x) // count the no of set bits in x
#define zerobits(x)            __builtin_ctzll(x) // count the no of zeros starting from the right most set bit
#define mod                   1000000007  //1e9+7
#define inf                   1e18
#define ps(x,y)               fixed<<setprecision(y)<<x // set the precision of x till y places of decimal
#define mka(arr,n,type)       type* arr = new type[n];
#define w(x)                  int x;cin>>x; while(x--)

vector<string> fun(int sx, int sy, int dx, int dy)
{
	// If destination found then fill a vector with empty string showing destination found
	if (sx == dx and sy == dy)
	{
		vector<string>v;
		v.push_back(" ");
		return v;
	}
	else if (sx > dx or sy > dy)
	{
		// If destination not found then return empty vector showing destination not found
		vector<string> v;
		return v;
	}
	else
	{

		vector<string>res;

		// recursively call the function for every possible horizontal step
		for (int i = 1; i <= dx - sx; i++)
		{
			vector<string> p1 = fun(sx + i, sy, dx, dy);
			for (auto j : p1)
				res.push_back("h" + to_string(i) + j);
		}

		// recursive call the function for every possible vertical step
		for (int i = 1; i <= dy - sy; i++)
		{
			vector<string> p1 = fun(sx, sy + i, dx, dy);
			for (auto j : p1)
				res.push_back("v" + to_string(i) + j);
		}

		// recursive call the function for every possible diagnol step in a grid

		for (int i = 1; i <= dx and i <= dy ; i++)
		{
			vector<string> p2 = fun(sx + i, sy + i, dx, dy);
			for (auto k : p2)
				res.push_back("d" + to_string(i) + k);

		}

		// return the possible paths  from current x,y to  destination to patent calle
		return res;

	}
}


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	vector<string> v = fun(0, 0, 3, 2);

	for (auto i : v)
		cout << i << " ";


	return 0;
}