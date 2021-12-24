// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here

        // Approach 1 (using next greater element using stack)

        // vector<int>res(n-k+1);
        // vector<int>nge(n);
        // stack<int>s;
        // int p=n-2;

        // s.push(n-1);
        // nge[n-1]=n;

        // for(int i=n-2;i>=0;i--)
        // {
        //     while(!s.empty() and arr[i] >= arr[s.top()])
        //     s.pop();

        //     if(s.empty())
        //     nge[p--]= n;
        //     else
        //     nge[p--]= s.top();

        //     s.push(i);
        // }

        // p=0;
        // int j=0;

        // for(int i=0;i<=n-k;i++)
        // {
        //     if(j<i)
        //     j=i;

        //     while(nge[j] < i+k)
        //     j = nge[j];

        //     res[p++]= arr[j];

        // }

        // return res;


        // Approach 2 (using deque)


        deque<int>q(k);
        vector<int>res;

        int i;

        for (i = 0; i < k; i++)
        {
            while (!q.empty() and arr[i] >= arr[q.back()])
                q.pop_back();

            q.push_back(i);
        }

        for (; i < n; i++)
        {
            res.push_back(arr[q.front()]);

            while (!q.empty() and q.front() <= i - k)
                q.pop_front();

            while (!q.empty() and arr[i] >= arr[q.back()])
                q.pop_back();

            q.push_back(i);

        }

        res.push_back(arr[q.front()]);

        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector <int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout << endl;

    }

    return 0;
}  // } Driver Code Ends