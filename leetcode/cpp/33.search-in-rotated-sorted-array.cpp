#include "oj_header.h"

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // 拓展的二分查找
        // 不存在重复的元素
        int l = 0, r = nums.size() - 1;
        this->nums = nums;
        this->target = target;

        int n = nums.size();

        if (n == 0)
            return -1;

        if (n == 1)
            return nums[0] == target ? 0 : -1;

        // n >= 2
        // [0,n-1] 闭区间
        int rotate_index = find_rotate_index(0, n - 1);

        // 最小的点
        if (nums[rotate_index] == target) {
            return rotate_index;
        }

        // 顺序增加的情况
        if (rotate_index == 0) {
            return binary_search(0, n - 1);
        }

        // 搜索后半部分
        if (target < nums[0]) {
            return binary_search(rotate_index, n - 1);
        }

        return binary_search(0, rotate_index - 1);
    }

    // 寻找最小的分界点
    int find_rotate_index(int left, int right)
    {
        //顺序的情况
        if (nums[left] < nums[right]) {
            return 0;
        }

        // 二分
        while (left <= right) {
            int mid = (left + right) / 2;
            //mid + 1 是旋转后的nums[0]
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            } else {
                if (nums[mid] < nums[left]) {
                    // 在后半段
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return 0;
    }

    // 标准的二分查找
    int binary_search(int left, int right)
    {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else {
                if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

private:
    int target;
    vector<int> nums;
};
