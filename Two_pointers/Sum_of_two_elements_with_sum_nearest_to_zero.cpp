// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    int closestToZero(int arr[], int n)
    {
        // your code here
        sort(arr, arr + n);
        int i = 0, j = n - 1;
        int sum = INT_MAX;
        int temp;

        while (i < j)
        {
            temp = arr[i] + arr[j];

            if (abs(temp) < abs(sum))
                sum = temp;

            else if (abs(temp) == abs(sum))
            {
                if (temp > 0)
                    sum = temp;
            }

            if (temp < 0)
                i++;
            else if (temp > 0)
                j--;
            else
                return 0;

        }

        return sum;
    }
};

// { Driver Code Starts.
int main ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends