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

vector<string> fun(string str)
{
	if (str.size() == 1)
	{
		vector<string>v;
		string s;
		s.push_back(str[0]);
		v.push_back("");
		v.push_back(s);
		return v;
	}
	else
	{
		char ch = str[0];
		string s = str.substr(1);

		vector<string>v = fun(s);

		vector<string>res;

		for (auto i : v)
		{
			res.push_back("" + i);
			res.push_back(ch + i);
		}

		return res;
	}
}



int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif


	string str;
	cin >> str;

	vector<string>v = fun(str);

	for (auto i : v)
		cout << i << " ";


	return 0;
}