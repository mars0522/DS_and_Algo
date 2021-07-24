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

bool is_safe(vector<vector<int>>& chess, int row, int col)
{
    // vertical checing
    for (int i = row - 1; i >= 0; i--)
    {
        if (chess[i][col] == 1)
            return false;
    }

// left diagnal checing
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0 ; i--, j--)
    {
        if (chess[i][j] == 1)
            return false;
    }

    // right diagnal  checking
    for (int i = row - 1, j = col + 1; i >= 0 and j < chess.size() ; i--, j++)
    {
        if (chess[i][j] == 1)
            return false;
    }

    return true;
}
void fun(vector<vector<int>>& chess, int row, string op)
{
    if (row == chess.size())
        cout << op << endl;
    else
    {
        for (int c = 0; c < chess.size(); c++)
        {
            if (is_safe(chess, row, c) == true)
            {
                chess[row][c] = 1;
                fun(chess, row + 1, op + to_string(row) + to_string(c) + ",");
                chess[row][c] = 0;
            }
        }
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif


    int n;
    cin >> n;

    vector<vector<int>> chess(n, vector<int>(n));
    fun(chess, 0, "");
    return 0;


}