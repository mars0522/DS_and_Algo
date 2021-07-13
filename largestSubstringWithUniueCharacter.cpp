
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

// Policy based data structure



int main()
{
#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	unordered_map<char, int> m;
	vector<string>v;

	//pair<pair<int, int>, int> > ws;
	int win_size = 0;

	int i = 0, j = 0;

	string str;
	cin >> str;

	while (j < str.length())
	{
		if (m.count(str[j]) and  m[str[j]] >= i)
		{
			// make a new size window
			i = m[str[j]] + 1;

		}


		m[str[j]] = j;
		j++;


		// store the size of previous window



		if (win_size < j - i )
		{
			string st(str.begin() + i, str.begin() + j);
			v.push_back(st);
			win_size = j - i ;
		}
	}

// Printing Maximum Window Size

	cout << v[v.size() - 1] << endl;
	cout << win_size << endl;


}