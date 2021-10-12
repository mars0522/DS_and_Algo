class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        set<vector<int>>s;
        vector<vector<int>>res;
        vector<int>v;

        if (n < 3) return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);

                    if (s.find(v) == s.end())
                    {
                        res.push_back(v);
                        s.insert(v);
                    }

                    j++;
                    k--;
                    v.clear();
                }

                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }

        }

        return res;

    }
};