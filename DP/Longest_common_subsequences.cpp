// { Driver Code Starts
#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.


    // Top Down approach
    int fun(vector<vector<int>>& dp, string s1, string s2, int i, int j)
    {
        if (i == s1.size() or j == s2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + fun(dp, s1, s2, i + 1, j + 1);
        else
        {
            int op1 = fun(dp, s1, s2, i + 1, j);
            int op2 = fun(dp, s1, s2, i, j + 1);

            return dp[i][j] = max(op1, op2);
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int n1 = s1.size();
        int n2 = s2.size();

        // Top Down appproach
        // vector<vector<int>>dp(n1+1, vector<int>(n2+1,-1));

        // return fun(dp,s1,s2,0,0);

        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1));

        for (int i = n1 - 1; i >= 0; i--)
        {
            for (int j = n2 - 1; j >= 0; j--)
            {
                char c1 = s1[i];
                char c2 = s2[j];

                if (c1 == c2)
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};


// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;    // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends