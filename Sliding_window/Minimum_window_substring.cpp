// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int sf[256] = {0};
        int pf[256] = {0};


        for (auto i : p)
            pf[i]++;

        int start = -1;
        int window = INT_MAX;
        int i = 0, j = 0;
        int count = 0;

        while (j < s.length())
        {
            char ch = s[j];

            sf[ch]++;

            if (pf[ch] and pf[ch] >= sf[ch])
                count++;

            if (count == p.length())
            {
                while (pf[s[i]] == 0 or sf[s[i]] > pf[s[i]])
                {
                    sf[s[i]]--;
                    i++;
                }

                if (window > (j - i + 1))
                {
                    start = i;
                    window = j - i + 1;
                }
            }

            j++;
        }

        if (start == -1)
            return "-1";
        else
            return s.substr(start, window);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;

    }
    return 0;
}  // } Driver Code Ends