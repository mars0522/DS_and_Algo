// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
	int lenOfLongSubarr(int arr[],  int n, int k)
	{
		// Complete the function
		long long sum = 0;
		unordered_map<long long, long long>mp;

		long long len = 0;
		mp[0] = -1;

		for (int i = 0; i < n; i++)
		{
			sum += arr[i];


			if (mp.find(sum) == mp.end())
				mp[sum] = i;

			if (mp.find(sum - k) != mp.end())
				len = max(len, i - mp[sum - k]);
		}

		return len;
	}

};

// { Driver Code Starts.

int main() {
	//code

	int t; cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int a[n];

		for (int i = 0; i < n; i++)
			cin >> a[i];
		Solution ob;
		cout << ob.lenOfLongSubarr(a, n , k) << endl;

	}

	return 0;
}  // } Driver Code Ends