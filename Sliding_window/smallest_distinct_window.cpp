// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string findSubString(string str)
    {
        // Your code goes here
        int window = INT_MAX;
        int i = 0, j = 0, count = 0;
        set<char>s;
        int start = -1;
        string patt = "";

        for (auto i : str)
        {
            if (s.find(i) == s.end())
            {
                s.insert(i);
                patt += i;
            }
        }

        int sf[256] = {0};
        int pf[256] = {0};

        for (auto i : patt)
            pf[i]++;

        while (j < str.size())
        {
            char ch = str[j];

            sf[ch]++;

            if (pf[ch] and pf[ch] >= sf[ch])
                count++;

            if (count == patt.size())
            {
                while (pf[str[i]] == 0 or sf[str[i]] > pf[str[i]])
                {
                    sf[str[i]]--;
                    i++;
                }

                if (window > j - i + 1)
                {
                    start = i;
                    window = j - i + 1;
                }
            }

            j++;
        }

        if (start == -1)
            return "";

        return str.substr(start, window);



    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}  // } Driver Code Ends