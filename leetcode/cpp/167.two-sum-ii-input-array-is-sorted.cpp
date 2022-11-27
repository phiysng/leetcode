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
