#include "array_util.h"
#include <exception>

/// 39 数组中出现次数超过一半的数字

/// help check functions
bool g_bInputInvalid = false;

/// 个人觉得不是很有必要 最好使用vector<>来替换，可以减少这种无效输出的检查
bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if (numbers == nullptr && length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
    int times = 0;
    for (int i = 0; i < length; ++i) {
        if (numbers[i] == number)
            times++;
    }

    bool isMoreThanHalf = true;
    if (times * 2 <= length) {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

int MoreThanHalfNum_v1(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;
    int middle = length / 2;
    int start = 0;
    int end = length - 1;
    int index = Partition(numbers, length, start, end);
    while (index != middle) {
        if (index > middle) {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        } else {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }
    int result = numbers[middle];
    if (!CheckMoreThanHalf(numbers, length, result))
        result = 0;
    return result;
}

/// v2  超过一半的数字保证那个数字可以抵消所有其他的数字
int MoreThanHalfNum_v2(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;
    int result = numbers[0]; //当前的数字
    int times = 1; //当前数字出现的次数
    for (size_t i = 1; i < length; i++) {
        /// 次数降为0时 换新的数字
        if (times == 0) {
            result = numbers[i];
            times = 1;
        } else {
            if (numbers[i] == result) {
                ++times;
            } else {
                --times;
            }
        }
    }
    if (!CheckMoreThanHalf(numbers, length, result))
        return 0;
    return result;
}