#include<bits/stdc++.h>
#define int long long int

using namespace std;


// question : Given a string, find the number of pairs of substrings of the string that are
//            anagram of each other.

vector<int> get_hash(string s, int i, int j)
{
	// calculating the hash value of the given string
	vector<int>h(26, 0);
	while (i <= j)
	{
		h[s[i] - 'a']++;
		i++;
	}

	return h;
}

int count_anagram(string s)
{
	int count = 0;

	map< vector<int>, int > mp;

	// generating all the substrings of a given string
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = i; j < s.length(); j++)
		{
			// calculating the hash value for each substring
			vector<int> res = get_hash(s, i, j);
			mp[res]++;
		}
	}

	for (auto p : mp)
	{
		if (p.second > 1)
		{
			count += (p.second * (p.second - 1)) / 2;
		}
	}

	return count;
}


int32_t main()
{
	string str;
	cin >> str;

	cout << count_anagram(str) << endl;
	return 0;


}