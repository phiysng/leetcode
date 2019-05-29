/// 49 丑数(求第n个丑数)

#include "array_util.h"
using namespace std;

bool IsUgly(int number)
{
    while (number % 2 == 0)
        number /= 2;
    while (number % 3 == 0)
        number /= 3;
    while (number % 5 == 0)
        number /= 5;

    return (number == 1) ? true : false;
}

int GetUglyNumber_v1(int index)
{
    if (index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while (uglyFound < index) {
        ++number;

        if (IsUgly(number))
            ++uglyFound;
    }

    return number;
}

// 空间换时间 只考虑 2 3 5的乘积

int GetUglyNumber_v2(int index)
{
    if (index <= 0)
        return 0;
    vector<int> res(index);
    res[0] = 1; //第一个丑数
    int i2 = 0, i3 = 0, i5 = 0;
    int currIdx = 1;
    while (currIdx < index) {
        int curr_min = min({ res[i2] * 2, res[i3] * 3, res[i5] * 5 });

        res[currIdx] = curr_min;

        /// 好像while改为if也是对的
        while (res[i2] * 2 == curr_min)
            ++i2;
        while (res[i3] * 3 == curr_min)
            ++i3;
        while (res[i5] * 5 == curr_min)
            ++i5;
        ++currIdx;
    }
    return res.back();
}
