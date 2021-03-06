#include <iostream>

using namespace std;
void dfs(int g[8][8],int u,int visited[])
{
   if(visited[u]==0)// if node is not visited
   {
      cout<<u<<" ";  // visit the node
      visited[u]=1;  // mark it as visited
      for(int v=0;v<8;v++)// visit the neighbour nodes v of node u
      {
         if(g[u][v]==1 && visited[v]==0)// if the neighbour node is not visited
         dfs(g,v,visited); //then visit it by putting previous node onto the stack
      }
   }

}
int main()
{
    int g[8][8]={0,1,0,0,0,0,1,0,// graph taken for example
                 1,0,0,0,1,0,0,0,
                 0,0,0,1,0,0,1,0,
                 0,0,1,0,0,0,0,0,
                 0,1,0,0,0,1,0,0,
                 0,0,0,0,1,0,0,0,
                 1,0,1,0,0,0,0,1,
                 0,0,0,0,0,0,1,0};

    int visited[8],start;
    for(int i=0;i<8;i++)
    visited[i]=0;// initialzing the visited array with zeros
    cout<<"\nEnter the starting point point: ";
    cin>>start;// enter the starting point from where the dfs is to be started
    dfs(g,start,visited);// calling the dfs function


    return 0;
}
