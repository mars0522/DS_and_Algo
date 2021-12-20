// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	string FirstNonRepeating(string str) {
		// Code here

		queue<char>q;
		string out = "";
		unordered_map<char, int>mp;

		for (auto ch : str)
		{
			mp[ch]++;

			if (mp.count(ch) == 1)
				q.push(ch);

			if (mp[q.front()] == 1)
				out += q.front();

			else
			{
				while (!q.empty() and mp[q.front()] != 1)
					q.pop();

				if (q.empty())
					out += "#";
				else

					out += q.front();
			}

		}

		return out;
	}

};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends