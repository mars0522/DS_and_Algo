
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


void explore(vector<vector<int>>& chess, int row , int col)
{
	if (row <0 or row >= chess.size() or col <0 or col >= chess.size() or chess[row][col] == 1)
		return ;

	else
	{
		chess[row][col] = 1;
		cout << row << col << ",";
		explore(chess, row - 2, col + 1);
		explore(chess, row - 1, col + 2);
		explore(chess, row + 1, col + 2);
		explore(chess, row + 2, col + 1);
		explore(chess, row + 2, col - 1);
		explore(chess, row + 1, col - 2);
		explore(chess, row - 1, col - 2);
		explore(chess, row - 2, col - 1);
	}
}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<vector<int>> chess(n, vector<int>(n));
	int i, j;
	cin >> i >> j;
	explore(chess, i, j);

	for (int i = 0; i < chess.size(); i++)
	{
		for (int j = 0; j < chess.size(); j++)
		{
			if (chess[i][j] == 1)
				cout << i << j << ",";
		}
		cout << endl;
	}



}


