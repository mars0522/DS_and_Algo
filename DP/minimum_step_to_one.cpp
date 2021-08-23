
#include<bits/stdc++.h>
using namespace std;
int dp[100];
int min(int x, int y, int z)
{
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

// top down approach
int fun1(int n)
{
    if (n == 1) return 0;

    if (dp[n] != -1) return dp[n];

    int h1 = fun1(n - 1);
    int h2 = INT_MAX;
    if (n % 2 == 0)
        h2 = fun1(n / 2);

    int h3 = INT_MAX;
    if (n % 3 == 0)
        h3 = fun1(n / 3);

    return (dp[n] = 1 + min(h1, h2, h3));
}

// botton up approach

int fun2(int n)
{
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int h1 = dp[i - 1];
        int h2 = INT_MAX;
        if (i % 2 == 0)
            h2 = dp[i / 2];
        int h3 = INT_MAX;
        if (i % 3 == 0)
            h3 = dp[i / 3];

        dp[i] = 1 + min(h1, h2, h3);
    }

    return dp[n];
}


int main()
{

    // for fast input output
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("opt_output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    // result from top down approach
    cout << fun1(n) << endl;
    memset(dp, -1, sizeof(dp));

    // result from  bottom up approach
    cout << fun2(n) << endl;




}