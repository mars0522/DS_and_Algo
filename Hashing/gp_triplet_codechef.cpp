/*

	....(द्वितीय अध्याय, श्लोक 47).....

    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन |
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि ||

....हिंदी अनुवाद: कर्म पर ही तुम्हारा अधिकार है, लेकिन कर्म के फलों में कभी नहीं… इसलिए
....कर्म को फल के लिए मत करो और न ही काम करने में तुम्हारी आसक्ति हो |

*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;

void solve() {

	int n, r;

	cin >> n >> r;

	vector<int>v(n);
	unordered_map<int, int>left, right;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		right[v[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		int c1 = 0;
		int c2 = 0;

		right[v[i]]--;

		c1 = left[v[i] / r];
		c2 = right[v[i] * r];

		count += c1 * c2;

		left[v[i]]++;
	}

	cout << count << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt",  "r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	clock_t z = clock();

	int t = 1;
	// cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}