// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
public:


	int search(string pat, string txt) {
		// code here

		vector<int>target(26, 0);
		vector<int>hash(26, 0);
		int count = 0;
		int n = pat.length();

		for (auto i : pat)
			target[i - 'a']++;

		int i;
		int j = 0;

		for (i = 0; i < n; i++)
			hash[txt[i] - 'a']++;

		if (hash == target)
			count++;

		while (i < txt.length())
		{
			hash[txt[j] - 'a']--;
			hash[txt[i] - 'a']++;

			if (hash == target)
				count++;

			i++;
			j++;
		}

		return count;


	}

};

// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		string pat, txt;
		cin >> txt >> pat;
		Solution ob;
		auto ans = ob.search(pat, txt);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends