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


void add_edge(list<int>* l, int i, int j)
{
    l[i].push_back(j);
    l[j].push_back(i);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif


    int n, m;
    cin >> n >> m;

    list<int>* l = new list<int>[n + 1];

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add_edge(l, a, b);
    }

    vector<int>dist(n + 1, -1);
    vector<int>parent(n + 1);
    vector<int>visited(n + 1);

    queue<int>q;
    q.push(1);
    visited[1] = 1;
    parent[1] = 1;
    dist[1] = 0;

    while (q.size() > 0)
    {
        int f = q.front();
        q.pop();
        for (auto node : l[f])
        {
            if (visited[node] == 0)
            {
                visited[node] = 1;
                dist[node] = dist[f] + 1;
                parent[node] = f;
                q.push(node);
            }
        }
    }


    int d = dist[n];

    if (d == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << d + 1 << endl;

        int index = n;
        stack<int>s;
        s.push(n);
        while (index != 1)
        {
            index = parent[index];
            s.push(index);
        }

        while (s.size() > 0)
        {
            cout << s.top() << " ";
            s.pop();
        }

    }

}