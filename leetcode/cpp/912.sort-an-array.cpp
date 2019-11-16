class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        //quick_sort(nums,0,nums.size());
        sort(begin(nums), end(nums));
        return nums;
    }

    void quick_sort(vector<int> &nums, int l, int r)
    {
        if (r - l <= 1)
            return;

        int idx = l + 1;
        int pivot = nums[l];
        // partition

        for (int i = l + 1; i < r; ++i)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[idx++]);
            }
        }
        cout << l << " " << r << "  " << idx << endl;
        // idx => begin of greater part
        swap(nums[l], nums[idx - 1]);
        quick_sort(nums, l, idx - 1);
        quick_sort(nums, idx, r);
    }
};
