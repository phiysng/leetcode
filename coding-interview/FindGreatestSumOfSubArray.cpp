/// 42 连续子数组的最大和
#include "array_util.h"
using namespace std;

// 假设数据都是有效的

// f(i) = array[i] when i = 0 || f(i-1) <= 0
//        f(i-1) + array[i] when i != 0 && f(i-1) > 0
int FindGreatestSumOfSubArray(vector<int> array)
{
    int curr = 0;
    int max_sum = INT_MIN;
    for (int i : array) {
        if (curr <= 0)
            curr = i;
        else {
            curr += i;
        }
        if (curr > max_sum)
            max_sum = curr;
    }
    return max_sum;
}
