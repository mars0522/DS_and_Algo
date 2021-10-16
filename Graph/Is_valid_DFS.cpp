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


vector<int> ind(1000000);
bool cmp(int x, int y)
{
    return ind[x] < ind[y];
}
void add_edge(vector<vector<int>>& g, int i, int j)
{
    g[i].push_back(j);
    g[j].push_back(i);
}

vector<int> dfs(vector<vector<int>>& g, int source, int n)
{
    vector<int>visited(n + 1);
    vector<int>v;
    queue<int>q;
    q.push(source);
    visited[source] = 1;

    while (q.size() > 0)
    {
        int f = q.front();
        q.pop();
        v.push_back(f);

        for (auto v : g[f])
        {
            if (visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
            }
        }


    }

    return v;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif


    int n;
    cin >> n;

    vector<vector<int>> g(n + 1);

    int x, y;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        add_edge(g, x, y);
    }

    vector<int> ip(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ip[i];
        ind[ip[i]] = i;
    }


    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end() , cmp);


    vector<int>ans = dfs(g, 1, n);

    if (ans == ip)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;




}