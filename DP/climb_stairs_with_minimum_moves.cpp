#include<bits/stdc++.h>
using namespace std;

int dp[100] = {0};

int min(int x, int y, int z)
{
    return x > y ? (x > z ? x : z) : (y > z ? y : z);
}
int fun(int n)
{
    if (n == 1) return 1;

    if (dp[n] != 0) return dp[n];

    int h1, h2, h3;
    h1 = h2 = h3 = INT_MAX;

    h1 = fun(n - 1);
    if (n % 2 == 0)
        h2 = fun(n / 2);
    if (n % 3 == 0)
        h3 = fun(n / 3);

    return dp[n] = min(h1, h2, h3);


}
int main()
{


    int n ;
    cin >> n;

    cout << fun(n) << endl;

}