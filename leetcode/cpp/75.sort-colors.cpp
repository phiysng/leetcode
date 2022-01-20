#include "oj_header.h"

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // 两个指针分别指向 0 || 2 当前的边界
        int zero = -1; //左边及 zero 都是0
        int two = nums.size(); //右边及two都是2
        int one = 0;

        while (one < two) {
            if (nums[one] == 0) {
                // 左边是00011这种
                // 将一个1 与 这个0交换
                ++zero;
                swap(nums[zero], nums[one]);
                ++one;
            } else {
                if (nums[one] == 2) {
                    //交换过来的可能是0 / 1 不能直接指向下一个节点
                    --two;
                    swap(nums[two], nums[one]);

                } else {
                    // 左边肯定都是1
                    ++one;
                }
            }
        }
    }
};
