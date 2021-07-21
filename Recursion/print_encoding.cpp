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


string str = "@abcdefghijklmnopqrstuvwxyz";

void  printEncoding(string ip, string op)
{
	if (ip.empty())
		cout << op << endl;
	else
	{
		char ch = ip[0];
		string rest1 = ip.substr(1);

		int k = ch - '0';

		if (k)
			printEncoding(rest1, op + str[k]);

		if (ip.size() >= 2)
		{
			string str1 = ip.substr(0, 2);
			string rest2 = ip.substr(2);

			int n = stoi(str1);

			if (n >= 10 and n <= 26)
				printEncoding(rest2, op + str[n]);
		}
	}
}
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif


	printEncoding("2344492034", "");





	return 0;
}