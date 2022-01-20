#include "oj_header.h"

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            // 如果头中尾相等,我们无法确定到底该分到哪一个部分,因此左右同时缩小范围
            // 直到范围不再满足
            while (left <= right && nums[left] == nums[mid] && nums[right] == nums[mid]) {
                ++left;
                --right;
            }
            if (left > right)
                break;
            // mid在左半边
            if (nums[left] <= nums[mid]) {
                //在左半边的有序序列二分
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid - 1;
                    return binary_saerch(nums, left, right, target);
                }
                //在另一边
                else {
                    left = mid + 1;
                }
            }
            // 在右半边
            else {
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                    return binary_saerch(nums, left, right, target);
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
    bool binary_saerch(vector<int> v, int left, int right, int target)
    {
        if (left > right)
            return false;

        if (v[left] == target || v[right] == target)
            return true;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (v[mid] == target)
                return true;

            if (v[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
};
