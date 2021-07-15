#include <bits/stdc++.h>
using namespace std;

// funtion for comparison in the element of the priority_queue
struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		return a.first > b.first;
	}
};

// Function to add edge and with in the graph
void add_edge(vector<pair<int, int>>adj[], int u, int v, int w)
{
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
}

// Dijkstra'a Algo
vector<int> dijkstra_algo(vector<pair<int, int>>adj[],  int vertices, int source)
{

	// Making a priority queue for pair(dist, vertex)
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>q;
	vector<int> dist(vertices, INT_MAX);
	dist[source] = 0;
	q.push({0, source});


	while (!q.empty())
	{
		int curr_vertex = q.top().second;
		int curr_dist = q.top().first;
		q.pop();

		for (auto e : adj[curr_vertex])
		{
			if (dist[e.first] > curr_dist + e.second)
			{
				dist[e.first] = curr_dist + e.second;
				q.push({dist[e.first], e.first});
			}
		}
	}

	return dist;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int e, vertices;
	cin >> vertices >> e;
	vector<pair<int, int>>adj[vertices];
	while (e--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add_edge(adj, u, v, w);
	}

	vector<int>dist = dijkstra_algo(adj, vertices, 0);

	for (int i = 0; i < dist.size(); i++)
		cout << dist[i] << " ";


}