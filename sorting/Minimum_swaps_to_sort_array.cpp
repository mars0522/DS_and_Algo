// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
public:
	//Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
		// Code here
		vector<pair<int, int>>ap;

		for (int i = 0; i < nums.size(); i++)
			ap.push_back({nums[i], i});

		sort(ap.begin(), ap.end());

		int cycle = 0;

		vector<bool> visited(nums.size(), false);

		for (int i = 0; i < ap.size(); i++)
		{
			if (visited[i] == true or i == ap[i].second)
				continue;
			else
			{
				int node = i;
				while (visited[node] == false)
				{
					visited[node] = true;
					cycle++;
					node = ap[node].second;
				}
				cycle--;
			}

		}

		return cycle;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int>nums(n);
		for (int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends