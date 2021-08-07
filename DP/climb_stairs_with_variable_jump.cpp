#include <bits/stdc++.h>
using namespace std;

// using tabulation method
int cs(int arr[], int n, vector<int>& dp) {
    // write your code here

    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i]; j++)
        {
            if (i + j < dp.size())
                dp[i] += dp[i + j];
        }
    }

    return dp[0];

    return 0;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    vector<int>dp(n + 1);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    cout << cs(arr, n, dp) << endl;
}