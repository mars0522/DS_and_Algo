#include <iostream>

using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
void juggling_algo(int a[],int n,int d)
{
    d=d%n;
    int i,j,k;
    int temp;
    for(i=0;i<gcd(n,d);i++)
    {
        j=i;
        temp=a[i];
        while(1)
        {
           k=(j+d)%n;
           if(k==i)
           break;
           a[j]=a[k];
           j=k;
        }
        a[j]=temp;

    }

}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    cout<<"\nBefore rotation the array looks like this: ";
    for(int i=0;i<7;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    cout<<"\nAfter the rotation the array looks like this: ";
    juggling_algo(a,7,2);
    for(int i=0;i<7;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
