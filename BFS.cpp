#include <iostream>
#include<queue>
using namespace std;
void dfs(int g[8][8],int visited[],queue<int>& q,int s)
{
  int u,v;
   cout<<s<<" ";// starting point of traversal
   visited[s]=1;// mark start point as visited node
   q.push(s);// push the start node into the queue
   while(!q.empty())//loop will iterate till queue becomes empty
   {
      u=q.front();
      q.pop();
      for(v=0;v<8;v++)// traversing the neighbours of the node u
      {
          if(g[u][v]==1 && visited[v]==0)// if node v is not visited then mark it as visited and enque it into the queue
                                         // v are the neighbours of the node u
          {
             cout<<v<<" ";
             visited[v]=1;
             q.push(v);
          }

      }

   }
}

int main()
// program complexity will be
{

    int g[8][8]={0,1,1,0,0,0,0,0,
                 1,0,1,1,1,0,0,0,
                 1,1,0,1,0,0,0,0,
                 0,1,1,0,1,1,0,0,
                 0,1,0,1,0,1,0,0,
                 0,0,0,1,1,0,1,1,
                 0,0,0,0,0,1,0,0,
                 0,0,0,0,0,1,0,0};// taken graph for example
    queue<int> q;
    int visited[8];
    int start;
    for(int i=0;i<8;i++)
    visited[i]=0;
    cout<<"\nEnter the starting vertex :";
    cin>>start; // getting the starting point from where the dfs is to be started
    dfs(g,visited,q,start);// calling dfs program

    return 0;
}
