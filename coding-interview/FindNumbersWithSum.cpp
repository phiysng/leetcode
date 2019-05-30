// 57 和为s的数字

/// 2sum leetcode 在递增的数组上
/// 双指针解法
#include "array_util.h"
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
    bool found = false;
    if (length < 1 || !num1 || !num2)
        return found;
    int ahead = length - 1;
    int behind = 0;
    while (ahead > behind) {
        long long curSum = data[ahead] + data[behind];

        if (curSum == sum) {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        } else {
            if (curSum > sum) {
                ahead--;
            } else {
                behind++;
            }
        }
    }
    return found;
}
/// 和为s的连续正数数列
void PrintContinuousSequence(int small, int big)
{
    for (int i = small; i < big + 1; i++) {
        printf("%d\t", i);
    }
    printf("\n");
}

void FindContinuousSequence(int sum)
{
    if (sum < 3)
        return;
    int small = 1;
    int big = 2;

    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while (small < middle) {
        if (curSum == sum) {
            PrintContinuousSequence(small, big);
        }

        while (curSum > sum && small < middle) {
            //左指针右移
            curSum -= small;
            small++;

            if (curSum == sum) {
                PrintContinuousSequence(small, big);
            }
        }
        // 右指针右移
        big++;
        curSum += big;
    }
}
