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


void floodfill(vector<vector<int>>& maze, int sx, int sy, int dx, int dy, vector<vector<int>>& visited, string op)
{

    if (sx < 0 or sy < 0 or sx == dx + 1 or sy == dy + 1 or visited[sx][sy] == 1)
        return ;
    else if (sx == dx and sy == dy)
    {
        cout << op << endl;
    }
    else
    {
        visited[sx][sy] = 1;
        floodfill(maze, sx - 1, sy, dx, dy, visited, op + "t");
        floodfill(maze, sx, sy - 1, dx, dy, visited, op + "l");
        floodfill(maze, sx + 1, sy, dx, dy, visited, op + "d");
        floodfill(maze, sx, sy + 1, dx, dy, visited, op + "r");
        visited[sx][sy] = 0;

    }

}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif






    return 0;
}