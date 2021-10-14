class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, int>mp;
        int ans = 0;
        int count = 0;

        for (auto i : nums)
            mp[i] = 1;

        for (auto i : nums)
        {
            if (mp.find(i - 1) == mp.end())
                mp[i] = 1;
            else
                mp[i] = 0;
        }

        for (auto i : nums)
        {
            if (mp[i] == 1)
            {
                count++;
                int j = i + 1;

                while (1)
                {
                    if (mp.find(j) != mp.end())
                    {
                        count++;
                        j++;
                    }
                    else
                        break;
                }

                ans  = max(ans, count);
                count = 0;
            }
        }

        return ans;



    }
};