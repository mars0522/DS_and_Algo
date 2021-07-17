#include<bits/stdc++.h>
using namespace std;

vector<string> fun(int n)
{
	if (n == 0)
	{
		vector<string> v;
		v.push_back(" ");
		return v;
	}
	else if (n < 0)
	{
		vector<string>v;
		return v;
	}


	else
	{
		vector<string> p1 = fun(n - 1);
		vector<string>p2 = fun(n - 2);
		vector<string>p3 = fun(n - 3);

		vector<string> res;

		for (auto s : p1)
		{
			s += "1";
			res.push_back(s);
		}

		for (auto s : p2)
		{
			s += "2";
			res.push_back(s);
		}

		for (auto s : p3)
		{
			s += "3";
			res.push_back(s);
		}

		return res;
	}
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("opt_output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<string> res = fun(n);
	for (auto s : res)
		cout << s << " ";

	return 0;
}