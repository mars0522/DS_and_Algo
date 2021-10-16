class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length())
            return "";


        int count = 0;
        int i = 0, j;
        int win_size = INT_MAX;
        int start = -1;

        int P[256] = {0};
        int W[256] = {0};


        // hasing the pattern string
        for (int i = 0; i < t.length(); i++)
            P[t[i]]++;

        for (j = 0; j < s.length(); j++ )
        {
            char ch = s[j];

            // including the current character to our window
            W[ch]++;

            // if current character is present in the pattern string the increment the count
            if (P[ch] != 0 and W[ch] <= P[ch])
                count++;

            if (count == t.length())
            {
                // start removing the unwanted characters from the windwo

                while (P[s[i]] == 0 or W[s[i]] > P[s[i]])
                {
                    W[s[i]]--;
                    i++;
                }

                if (win_size > j - i + 1)
                {
                    win_size = j - i + 1;
                    start = i;
                }
            }
        }

        if (start == -1)
            return "";
        else
            return s.substr(start, win_size);


    }
};