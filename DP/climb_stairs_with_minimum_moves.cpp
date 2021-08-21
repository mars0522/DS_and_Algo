#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int dp[n + 1] = {0};

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            dp[i] = INT_MAX;
            continue;
        }
        int ans = INT_MAX;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j <= n)
                ans = min(ans, dp[i + j]);
        }

        if (ans == INT_MAX)
            dp[i] = ans;
        else
            dp[i] = 1 + ans;
    }

    cout << dp[0] << endl;


}