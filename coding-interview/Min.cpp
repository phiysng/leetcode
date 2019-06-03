// 11 旋转数组的最小数字

/// 比较有意思
#include "array_util.h"
using namespace std;

// fallback function
int MinInOrder(int* numbers, int left, int right)
{
    int res = numbers[left];

    for (int i = left + 1; i < right + 1; i++) {
        res = min(res, numbers[i]);
    }
    return res;
}

int Min(int* numbers, int length)
{
    if (!numbers || length <= 0)
        throw new exception("invalid parameter.");

    int left = 0;
    int right = length - 1;
    int mid = left;

    while (numbers[left] >= numbers[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
        mid = (left + right) / 2;
        
        /// 特殊情况 前中后数字大小相同 fallback到O(n)的遍历
        if (numbers[left] == numbers[right] && numbers[mid] == numbers[left])
            return MinInOrder(numbers, left, right);

        if (numbers[mid] >= numbers[left])
            left = mid;
        else if (numbers[mid] <= numbers[right])
            right = mid;
    }
    return numbers[mid];
}
