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


vector<int>v;
void add_edge(vector<vector<int>>& g, int i , int j)
{
    g[i].push_back(j);
    g[j].push_back(i);
}

void dfs(vector<vector<int>>& g, vector<int>& visited , int s)
{
    visited[s] = 1;
    v.push_back(s);
    for (auto node : g[s])
    {
        if (visited[node] == 0)
        {
            dfs(g, visited, node);
        }
    }

}


int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif


    int n, p;
    cin >> n >> p;

    vector<vector<int>>g(n);
    vector<int>visited(n);
    vector<long long>comp;

    int a, b;

    for (int i = 0; i < p; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(g, visited, i);
            comp.push_back(v.size());
            v.clear();
        }
    }

    long long count = (long long)(n) * (n - 1) / 2;
    cout << count << endl;

    for (int i = 0; i < comp.size() ; i++)
    {
        if (comp[i] >= 2)
            count -= (comp[i] * comp[i] - 1) / 2;
    }

    cout << count << endl;






}