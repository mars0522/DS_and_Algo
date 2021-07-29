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

class graph
{
    list<int>* g;
    int V;
public:
    graph(int v)
    {
        V = v;
        g = new list<int>[V];
    }

    void add_edge(int i, int j);
    bool dfs_helper( vector<int>& visited, int s, int p);
    bool is_cyclic();

};

void graph:: add_edge( int i, int j)
{
    g[i].push_back(j);
    g[j].push_back(i);
}
bool graph:: dfs_helper(vector<int>& visited, int s, int p)
{
    visited[s] = 1;
    for (auto nbr : g[s])
    {
        if (visited[nbr] == 0)
        {
            if (dfs_helper( visited, nbr, s) == true)
                return true;
        }
        else if (nbr != p)
            return true;
    }

    return false;
}
bool graph:: is_cyclic()
{
    vector<int> visited(V);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs_helper( visited, i, -1) == true)
                return true;
        }
    }

    return false;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif

    graph g(8);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    //g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(4, 3);

    g.add_edge(5, 6);
    g.add_edge(6, 7);
    g.add_edge(5, 7);

    if (g.is_cyclic() == true)
        cout << "Graph contains a cycle" << endl;
    else
        cout << "Graph Does not contain a cycle" << endl;





}