#include "oj_header.h"

class Solution {
 public:
  bool check(vector<int>& nums) {
    auto size = nums.size();
    for (int i = 0; i < size; ++i) {
      // 从 index i 开始的数组有序
      if (is_order(nums, i))
        return true;
    }
    return false;
  }

  bool is_order(vector<int>& nums, int index) {
    int prev = nums[index];
    int size = nums.size();
    for (int j = 1; j < size; ++j) {
      int currIdx = (index + j) % size;
      if (nums[currIdx] < prev)
        return false;
      prev = nums[currIdx];
    }
    return true;
  }
};
