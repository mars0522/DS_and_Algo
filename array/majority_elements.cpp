#include<iostream>
using namespace std;
void reverse_in_group(int a[],int n,int k)
{
    for(int i=0;i<n;i=i+k)
    {
        int l=i,h,temp;
        if(i+k-1 < n)
        h=i+k-1;
        else
        h=n-1;
        while(l<h)
        {
            temp=a[l];
            a[l]=a[h];
            a[h]=temp;
            l++;
            h--;
        }
    }
}
int main()
{
  int a[]={1,2,3,4,5,6,7,8,9};
  cout<<"\nBefore the reversing the array is: ";
  for(int i=0;i<9;i++)
  cout<<a[i]<<" ";
  cout<<endl;
  reverse_in_group(a,9,5);
  cout<<"\nAfter reversing the array : ";
  for(int i=0;i<9;i++)
  cout<<a[i]<<" ";
}
