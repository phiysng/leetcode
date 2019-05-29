/// 3 数组中的重复数字

#include "array_util.h"
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        /// 数据有效性的检查
        if (numbers == nullptr || length <= 0)
            return false;
        for (int i = 0; i < length; i++) {
            if (numbers[i] < 0 || numbers[i] > length - 1)
                return false;
        }
        for (int i = 0; i < length; i++) {
            while (numbers[i] != i) {
                if (numbers[i] == numbers[numbers[i]]) {
                    *duplication = numbers[i];
                    return true;
                }
                /// swap
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
        return false;
    }
    /// 题目二 不修改数组找出重复的数字
    int getDuplication(const int* numbers, int length)
    {
        if (numbers == nullptr || length <= 0)
            return -1;
        int start = 1, end = length - 1;
        while (end >= start) {
            int mid = (end - start) / 2 + start;
            int cnt = countRange(numbers, length, start, mid);
            // 结束状态
            if (end == start) {
                if (cnt > 1)
                    return start;
                else
                    break; ///无符合的情况
            }
            if (cnt > (mid - start + 1)) //前半部分有重复
                end = mid;
            else
                start = mid + 1;
        }
        return -1;
    }
    /// 返回 [start,end]范围内的数字的数量
    int countRange(const int* numbers, int length, int start, int end)
    {
        if (numbers == nullptr)
            return 0;
        int count = 0;
        for (int i = 0; i < length; i++) {
            if (numbers[i] >= start && numbers[i] <= end) {
                ++count;
            }
            return count;
        }
    }
};
