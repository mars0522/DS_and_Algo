#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void add_edge(vector<int> g[], int u, int v)
{
   // in case of undirected graph
   // first add edge from u to v
   // then add edge from v to u
     g[u].push_back(v);
     g[v].push_back(u);
}
void print_graph(vector<int> g[],int v)
{
      for(int i=0;i<v;i++)
      {
        cout<<i<<": "; // specifying the vertex number
         for(int x: g[i])// iterating in each vector
         cout<<x<<"  ";
         cout<<endl;
      }

}
void BFS(vector<int> g[],int v,int start)
{
   int u,visited[v];
   queue<int> q;
   for(int i=0;i<v;i++)
   visited[i]=0;
   q.push(start);
   while(!q.empty())
   {
      u=q.front();
      q.pop();
      visited[u]=1;
      cout<<u<<" ";
      for(int v: g[u])
      {
         if(visited[v]==0)
         {
            visited[v]=1;
            q.push(v);
         }
      }


   }

}

int main()
{
   int v=5;
   vector<int> g[v];// undirected graph
   add_edge(g,0,1);
   add_edge(g,0,2);
   add_edge(g,0,4);
   add_edge(g,1,4);
   add_edge(g,2,4);
   add_edge(g,2,3);
   add_edge(g,3,4);
   print_graph(g,5);
   cout<<"\nBFS traversal of the graph is: ";
   BFS(g,5,0);
    return 0;
}
