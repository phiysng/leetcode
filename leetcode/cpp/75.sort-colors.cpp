class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        int zero = -1;
        int two = nums.size();
        int i = 0;
        while (i < two) {
            if (nums[i] == 0) {
                swap(nums[i], nums[++zero]);
                ++i;
                continue;
            } else {
                if (nums[i] == 2) {
                    swap(nums[i], nums[--two]);
                } else {
                    ++i;
                }
            }
        }
    }
};