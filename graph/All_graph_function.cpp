
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
	// number of vertices of a graph
	int V;
	// pointer to an array of type list<int>
	list<int>* l;
public:

	// constructor for initializing the graph
	graph(int v)
	{
		V = v;
		l = new list<int>[V];
	}
	// utility function to add edge to the graph
	void add_edge(int i, int j, bool undir = true);
	// utility function to display the graph
	void display();
	void bfs(int source);
	void dfs_helper(int source, vector<int>& visited);
	void dfs(int source);
	void shortest_path(int source, int destination = -1);

};

void graph:: add_edge(int i, int j, bool undir)
{
	l[i].push_back(j);
	if (undir)
		l[j].push_back(i);
}

void graph::bfs(int source)
{
	vector<int>visited(V);
	queue<int>q;
	q.push(source);
	visited[source] = 1;

	while (q.size() > 0)
	{
		int f = q.front();
		q.pop();

		cout << f << " ";
		for (auto v : l[f])
		{
			if (visited[v] == 0)
			{
				visited[v] = 1;
				q.push(v);
			}
		}
	}

	cout << endl;

}

void graph::dfs_helper(int source, vector<int>& visited)
{
	visited[source] = 1;
	cout << source << " ";

	for (auto node : l[source])
	{
		if (visited[node] == 0)
			dfs_helper(node, visited);
	}
	return;

}
void graph:: dfs(int source)
{
	vector<int>visited(V);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == 0)
			dfs_helper(i, visited);
	}

}

void graph:: display()
{
	for (int i = 0; i < V; i++)
	{
		cout << i << "-->";
		for (auto i : l[i])
		{
			cout << i << ",";
		}
		cout << endl;
	}
}

void graph:: shortest_path(int source, int destination )
{
	vector<int>dist(V);
	vector<int>visited(V);
	vector<int> parent(V, -1);

	queue<int>q;
	q.push(source);
	visited[source] = 1;
	parent[source] = source;

	while (q.size() > 0)
	{
		int f = q.front();
		q.pop();

		for (auto v : l[f])
		{
			if (visited[v] == 0)
			{
				visited[v] = 1;
				parent[v] = f;
				dist[v] = dist[f] + 1;
				q.push(v);
			}
		}
	}

	// Priting the shorest path from the source to all other vertices
	cout << "Shortest Distace of the all the vertice from " << source << " is: " << endl;

	for (int i = 0; i < dist.size(); i++)
	{
		cout << i << ":" << dist[i] << endl;
	}

	// Printing the Path from  source to destination

	if (destination )
	{
		int index = destination;
		stack<int>s;
		s.push(destination);
		while (index != source)
		{
			index = parent[index];
			s.push(index);

		}

		cout << "\n The path from " << source << " to " << destination << " is " << endl;
		while (s.size() > 0)
		{
			cout << s.top() << " ";
			s.pop();
		}

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

	graph g(6);
	g.add_edge(0, 2);
	g.add_edge(0, 4);
	g.add_edge(2, 5);
	g.add_edge(1, 5);
	g.add_edge(1, 3);
	g.add_edge(3, 4);



	cout << "This is my Graph: " << endl;
	g.display();

	cout << "This is the BFS traversal of the Graph: " << endl;
	g.bfs(0);

	g.shortest_path(0, 6);

	cout << "\nDFS Traversal of the Graph is as Follows: " << endl;

	g.dfs(0);




}


