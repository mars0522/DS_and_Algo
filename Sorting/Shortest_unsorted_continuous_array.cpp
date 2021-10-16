class Solution {
public:

    bool out_of_order(vector<int>&arr, int i)
    {
        int x = arr[i];
        int n = arr.size();

        if (i == 0) return x > arr[1];
        else if (i == n - 1) return arr[i - 1] > arr[i];

        else
            return x > arr[i + 1] or x < arr[i - 1];


    }
    int findUnsortedSubarray(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) return 0;

        int smallest = INT_MAX;
        int largest = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (out_of_order(nums, i))
            {
                smallest = min(smallest, nums[i]);
                largest = max(largest, nums[i]);
            }
        }

        int i = 0, j = n - 1;

        if (smallest == INT_MAX)
            return 0;

        while (i<n and smallest >= nums[i])
            i++;
        while (j >= 0 and largest <= nums[j])
            j--;

        return (j - i + 1);
    }
};