#include<bits/stdc++.h>

using namespace std;

class node
{
public:
	char d;
	bool is_terminal;
	unordered_map<char, node*> mp;
	node(char data)
	{
		d = data;
		is_terminal = false;
	}

};

class trie
{
	node* root;
public:
	trie()
	{
		root = new node('\0');
	}
	void insert(string word)
	{
		node* temp = root;
		for (auto ch : word)
		{
			if (temp->mp.count(ch) == 0)
			{
				node* n = new node(ch);
				temp->mp[ch] = n;
			}

			temp = temp->mp[ch];

		}

		temp->is_terminal = true;
	}

	bool search(string word)
	{
		node* temp = root;
		for (auto ch : word)
		{
			if (temp->mp.count(ch) == 0)
				return false;
			else

				temp = temp->mp[ch];

		}

		return temp->is_terminal;
	}

};

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	string word[] = {"apple", "ape", "no", "news", "not", "never"};

	trie t;

	for (auto s : word)
		t.insert(s);

	int q;
	cin >> q;

	while (q--)
	{
		string str;
		cin >> str;

		if (t.search(str))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}


}