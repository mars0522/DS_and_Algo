#include <iostream>

using namespace std;
// this program is about finding number of set bits in the binary representation of the integers
// Brian karnighan Algorithm
// Complexity is O(no of sets bits)
int No_of_bits_set(int n)
{
    int r=0;
    while(n>0)
    {
       n=n&(n-1);// In each iteration right side set bit is reset
       r++;// each time counting when the right side bit is reset
    }
    return r;// returning the value of number of bits were set into the given number
}
int main()
{
    int n;
    cout<<"\nEnter the value of n: ";
    cin>>n;
    cout<<"\nNo of bits set in the binary representation of "<<n<<" are: "<<No_of_bits_set(n)<<endl;

    return 0;
}
