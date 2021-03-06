#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int joseph(vector<int>& v,int k,int ci=0)
{
    vector<int>::iterator itr;
    if(v.size()==1)
    return v[0];
    else
    {
       itr=find(v.begin(),v.end(),v[(ci+k-1)%v.size()]);
       v.erase(itr);
       if(ci>v.size())
       ci=ci%v.size();
       else
       ci=(ci+k-1)%v.size();
       return joseph(v,k,ci);
    }
}

int main()
{

    vector<int> v;
    int n;
    cout<<"\nEnter the number of persons  in the game: ";
    cin>>n;
    for(int i=0;i<n;i++)
    v.push_back(i+1);


    cout<<joseph(v,2);

    return 0;
}
