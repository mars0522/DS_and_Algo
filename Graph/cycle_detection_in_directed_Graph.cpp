#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<vector<int>>& g, int i, int j)
{
    g[i].push_back(j);

}

bool dfs(vector<vector<int>>& g, vector<int>& visited, vector<int>& stack, int s)
{
    visited[s] = 1;
    stack[s] = 1;

    for (auto nbr : g[s])
    {
        if (visited[nbr] == 0)
        {
            if (dfs(g, visited, stack, nbr))
                return true;
        }
        else if (stack[nbr] == 1)
            return true;
    }

    stack[s] = 0;
    return false;
}
bool solve(int n, vector<vector<int>>edges) {

    vector<vector<int>> g(n + 1);
    vector<int>visited(n + 1);
    vector<int>stack(n + 1);

    for (auto v : edges)
    {
        add_edge(g, v[0], v[1]);
    }

    for (int i = 0; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(g, visited, stack, i))
                return true;
        }

    }

    return false;

}