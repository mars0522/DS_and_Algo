#include <iostream>
#include<stack>
using namespace std;
// leaders in the array is the problem in which we have to print that element in the array wrt which no element is greater on
// right side of the array
// This is solution in O(n)
void leader_in_array(int a[],int n,stack<int>& s)
{
    int mx=a[n-1];
    s.push(mx);// last element will always be in array
    for(int i=n-2;i>=0;i--)
    {// traversing the array from right to left side to optimize the problem
        if(a[i]> mx)
        {
           mx=a[i];
           s.push(mx);
        }
    }
}
int main()
{
  int a[]={5,3,20,15,8,25,3};
  stack<int> s;
  leader_in_array(a,sizeof(a)/(sizeof(int)),s);
  cout<<"\nLeader element in the array are: ";
  while(!s.empty())
  {
     cout<<s.top()<<"  ";
     s.pop();
  }

}
