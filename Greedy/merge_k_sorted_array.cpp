// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here

        vector<int>ans;
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>> >q;

        for (int i = 0; i < k; i++)
        {
            q.push({arr[i][0], i, 0});
        }

        while (q.size() > 0)
        {
            auto top = q.top();
            q.pop();

            int ele = top[0];
            int arr_index = top[1];
            int ele_index = top[2];

            ans.push_back(ele);

            if (ele_index + 1 < k)
            {
                q.push({arr[arr_index][ele_index + 1], arr_index, ele_index + 1});
            }
        }

        return ans;

    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int> (N, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}





// } Driver Code Ends