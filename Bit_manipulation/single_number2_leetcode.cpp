class Solution {
public:
    int singleNumber(vector<int>& nums) {

        vector<int>v(32);
        int sum = 0;

        for (int i = 0; i < 32; i++)
        {
            sum = 0;

            for (auto j : nums)
            {
                if (j & (1 << i))
                    sum++;
            }

            v[i] = sum % 3;
        }

        reverse(v.begin(), v.end());

        int ans = 0;

        for (auto i : v)
            cout << i;
        cout << endl;

        for (int i = 0; i < 32; i++)
        {
            ans = ans + (1 << (31 - i)) * v[i];
        }

        return ans;



    }
};