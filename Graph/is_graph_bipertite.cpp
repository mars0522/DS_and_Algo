#include<bits/stdc++.h>
using namespace std;

bool fun(vector<vector<int>>& g, vector<int>& visited, int s, int color)
{
    visited[s] = color;
    for (auto nbr : g[s])
    {
        if (visited[nbr] == 0)
        {
            if (fun(g, visited, nbr, 3 - color) == false)
                return false;
        }
        else if (color == visited[nbr])
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>> graph) {

    int n = graph.size();
    vector<int>visited(n);
    int color = 1;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (fun(graph, visited, i, color) == false)
                return false;
        }
    }

    return true;

}