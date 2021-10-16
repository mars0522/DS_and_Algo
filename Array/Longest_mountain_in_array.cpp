class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int peak = INT_MIN;

        int n = arr.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1])
            {
                int j = i - 1, k = i + 1;

                while (j > 0 and arr[j] > arr[j - 1] )
                    j--;

                while (k < n - 1 and arr[k] > arr[k + 1])
                    k++;

                peak = max(peak, k - j + 1);
            }
        }

        if (peak == INT_MIN)
            return 0;
        else
            return peak;

    }
};