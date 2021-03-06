#include <iostream>
#include<bits/stdc++.h>
// T(n) = O(nloglog(n))
using namespace std;
vector<int> prime(int n)
{
    vector<int> v(n+1,1);
    v[0]=v[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(v[i]==1)
        {
            for(int j=2;i*j<=n;j++)
               v[i*j]=0;
        }
    }
    return v;

}

int main()
{
    int n;
    cout<<"\nEnter the number: ";
    cin>>n;
    vector<int>v = prime(n);
    n=v.size();
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
            cout<<i<<" ";

    }
    return 0;
}
