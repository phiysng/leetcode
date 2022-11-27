#include "oj_header.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    // 二分查找
    for (int i = 0; i < numbers.size(); ++i) {
      int rest = target - numbers[i];
      int idx = binary_search(numbers, i + 1, numbers.size(), rest);
      if (idx >= 0) {
        return {i + 1, idx + 1};
      }
    }

    return {0, 0};
  }

  /**
   * @param start 开始位置(包含)
   * @param end 计结束位置(不包含)
   */
  int binary_search(vector<int>& nums, int start, int end, int target) {
    if (start >= end)
      return -1;

    int mid = (start + end) / 2;
    int value = nums[mid];
    if (value == target)
      return mid;
    if (value > target) {
      return binary_search(nums, start, mid, target);
    }

    return binary_search(nums, mid + 1, end, target);
  }
};

/**
 * @brief 双指针
 *
 * 0 <= left < right <= numbers.size() - 1
 * 假设解的坐标分别为i和j,除非i == 0 && j = nums.size(),
 * 否则肯定是left或right其中一个先到达i/j.
 *
 * 假设left先到达i,则此时 nums[left]+nums[right] >= target ,
 * 此时肯定是right--,left不会再朝右移动 同理, 假设right先到达j,则此时
 * nums[left]+nums[right] <= target , left--,right不会再向左移动
 *
 */
class SolutioV2 {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
      int value = numbers[left] + numbers[right];
      if (value == target)
        return {left + 1, right + 1};
      if (value > target) {
        --right;
      } else {
        ++left;
      }
    }

    return {0, 0};
  }
};
