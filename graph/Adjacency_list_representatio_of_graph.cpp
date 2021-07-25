
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
	void add_edge(int i, int j, bool undir = true)
	{
		l[i].push_back(j);
		if (undir)
			l[j].push_back(i);
	}

	// utility function to display the graph
	void display()
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
};




int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	graph g(5);
	g.add_edge(0, 1);
	g.add_edge(0, 4);
	g.add_edge(0, 3);
	g.add_edge(0, 2);
	g.add_edge(2, 3);
	g.add_edge(3, 4);
	g.add_edge(4, 1);

	g.display();




}


