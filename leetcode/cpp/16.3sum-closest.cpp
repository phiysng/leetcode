class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(begin(nums), end(nums));
        int res = 0x00ffffff;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            if (j >= nums.size() - 1)
                break;
            while (j < k) {
                int t = nums[i] + nums[j] + nums[k];
                if (abs(t - target) < abs(res - target)) {
                    res = nums[i] + nums[j] + nums[k];
                }
                if (t > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }

        return res;
    }
};
