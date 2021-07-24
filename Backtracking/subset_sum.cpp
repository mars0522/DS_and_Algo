#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ff                    first
#define ss                    second
#define ll                    long long
#define pb                    push_back
#define mp                    make_pair
#define pii                   pair<int,int>
#define vi                    vector<int>
#define mii                   map<int,int>
#define pqb                   priority_queue<int>
#define pqs                   priority_queue<int,vi,greater<int>>
#define setbits(x)            __builtin_popcountll(x) // count the no of set bits in x
#define zerobits(x)            __builtin_ctzll(x) // count the no of zeros starting from the right most set bit
#define mod                   1000000007  //1e9+7
#define inf                   1e18
#define ps(x,y)               fixed<<setprecision(y)<<x // set the precision of x till y places of decimal
#define mka(arr,n,type)       type* arr = new type[n];
#define w(x)                  int x;cin>>x; while(x--)


vector<vector<int>>res;

void fun(vector<int>& ip, int i, int sum, int target, vector<int> op)
{
    if (sum == target)
    {

        res.push_back(op);
        return;
    }
    else if (i == ip.size())
        return;
    else
    {
        vector<int> op1(op);
        vector<int> op2(op);
        op1.push_back(ip[i]);

        fun(ip, i + 1, sum + ip[i], target, op1);
        fun(ip, i + 1, sum, target, op2);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif

    int n, target;
    cin >> n;

    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    cin >> target;

    vector<int>op;

    fun(v, 0, 0, target, op);

    for (auto v : res)
    {
        for (auto i : v)
            cout << i << " ";

        cout << endl;
    }

    return 0;


}