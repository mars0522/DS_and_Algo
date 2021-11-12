class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int n1, n2, ans = 0;

        vector<int>res;

        for (auto i : nums)
            ans = ans ^ i;

        int temp = ans;
        int pos = 0;

        while (temp)
        {
            if (temp & 1)
                break;
            else
            {
                pos++;
                temp = temp >> 1;
            }
        }

        int dummy_ans = 0;

        for (auto i : nums)
        {
            if ((i & (1 << pos)))
                dummy_ans = dummy_ans ^ i;
        }

        res.push_back(dummy_ans);
        res.push_back(ans ^ dummy_ans);
        return res;



    }
};