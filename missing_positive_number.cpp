#include<iostream>
#include<cstdlib>
using namespace std;
// this is swap function
void swp(int* a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
// This is a segregate function which is used to align -ve including 0 elements to the left and +ve elements to the right side
int segregate(int* a,int n)
{
    int i=0,j=n-1;
    while(i<=j)
    {
        while(i<n && a[i]<=0)
        i++;
        while(j>=0 && a[j]>0)
        j--;
        if(i<j)
        swp(&a[i],&a[j]);
    }
    // returning the index of the first positive number in the segregated array
    return i;
}
int first_missing_positive_number(int* a,int n)
{
    int s=segregate(a,n);
    if(s>=n)// if returned index exceeds the boundary of array that means array is full of -ve numbers in that case
    // least missing positive number will be 1 only
    return 1;
    int true_index;
    // otherwise we will bring  our earlier array pointer to start from where all positive elements are stored
    a=a+s;
    n=n-s;// now number of elements are also reduced  because -ve elements are filtered out

    // from here we will start hashing technique to find min positive missing number in the same given array without using
    // any extra space
    for(int i=0;i<n;i++)
    {
       true_index=abs(a[i])-1;// finding the index position of element a[i]
       if(true_index < n && a[true_index] >0)// if index exits in the given array and element at that index is positive
       a[true_index]=-a[true_index];// then make that element as negative

    }
    for(int i=0;i<n;i++)
    {
       if(a[i]>0)// trying to find very first positive element in the array and this will give least positive missing number
       return i+1;
    }
    return n+1;// if all element in the array are negative that means least positive missing number is n+1

}
int main()
{
    int a[]={-47, 1, 4, 49, -18, 10, 26, 18, -11, -38 ,-24 ,36 ,44 ,-11 ,45 ,20 ,-16 ,28, 17, -49, 47, -48, -33, 42 ,2 ,6, -49, 30, 36, -9, 15, 39, -6, -31, -10, -21, -19, -33, 47 ,21 ,31, 25, -41, -23, 17, 6, 47 ,3 ,36, 15, -44, 33, -31, -26 ,-22 ,21 ,-18 ,-21 ,-47, -31 ,20, 18 ,-42, -35, -10, -1, 46, -27, -32 ,-5 ,-4, 1, -29 ,5, 29, 38, 14, -22, -9 ,0 ,43 ,-50, -16, 14, -26};
    int n=sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl<<endl;
    cout<<"\nMissing element in the array  is :"<<first_missing_positive_number(a,n)<<endl;

}
