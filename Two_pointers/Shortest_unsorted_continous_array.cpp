class Solution {
public:

    bool out_of_order(vector<int>& arr, int i)
    {
        int x = arr[i];

        if (i == 0) return x > arr[1];
        else if (i == arr.size() - 1) return arr[i - 1] > x;
        else
            return (x < arr[i - 1] or x > arr[i + 1]);
    }
    int findUnsortedSubarray(vector<int>& nums) {


        int smallest = INT_MAX;
        int largest = INT_MIN;

        if (nums.size() == 1) return 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (out_of_order(nums, i))
            {
                smallest = min(smallest, nums[i]);
                largest = max(largest, nums[i]);
            }
        }


        int i = 0;
        int j = nums.size() - 1;

        if (smallest == INT_MAX) return 0;

        while (i<nums.size() and smallest >= nums[i])
            i++;
        while (j >= 0 and largest <= nums[j])
            j--;

        return (j - i + 1);



    }
};