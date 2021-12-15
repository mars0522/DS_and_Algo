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

class point
{
public:
	int x, y;
	point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}


};

class cmp
{
public:
	bool operator()(const point p1, const point p2)
	{
		if (p1.x == p2.x)
			return p1.y < p2.y;
		else
			return p1.x < p2.x;
	}

};

void solve() {

	int n;
	int x, y;
	int ter;
	int ans = 0;

	set<point, cmp>s;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		point p(x, y);
		s.insert(p);
	}

	cin >> ter;

	for (auto it = s.begin(); it != prev(s.end()); it++)
	{
		for (auto jt = next(it); jt != s.end(); jt++)
		{
			auto p1 = *it;
			auto p2 = *jt;

			if (p1.x == p2.x or p1.y == p2.y)
				continue;

			point p3(p1.x, p2.y);
			point p4(p2.x, p1.y);

			if (s.find(p3) != s.end() and s.find(p4) != s.end())
				ans++;
		}
	}

	cout << ans / 2 << endl;


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
	//cin >> t;
	while (t--) solve();

	cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

	return 0;
}