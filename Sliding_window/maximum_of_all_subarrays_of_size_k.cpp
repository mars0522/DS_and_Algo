class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        stack<int>s;
        vector<int>nge(n);
        vector<int>res(n - k + 1);
        nge[n - 1] = n;
        s.push(n - 1);

        int p = n - 2;

        for (int j = n - 2; j >= 0; j--)
        {
            while (!s.empty() and nums[j] >= nums[s.top()])
                s.pop();

            if (s.empty())
                nge[p--] = n;
            else
                nge[p--] = s.top();

            s.push(j);
        }


        p = 0;

        int j = 0;
        for (int i = 0; i <= n - k; i++)
        {
            if (j < i)
                j = i;

            while (nge[j] < i + k)
                j = nge[j];

            res[p++] = nums[j];
        }

        return res;
    }
};