// 48 最长不含重复字符的子字符串
#include "array_util.h"
using namespace std;

/// DP 判断当前的字符上次出现的位置是否在当前所在的子串中

int longestSubstringWithoutDuplication(const string& str)
{
    int currentLength = 0;
    int maxLength = 0;
    vector<int> position(26, -1);
    for (int i = 0; i < str.length(); i++) {
        int prevIdx = position[str[i] - 'a'];
        // 如果不存在或者不在当前计算的字符串的区间内
        // abcda i = 4 len = 3 prevIdx = 0
        if (prevIdx < 0 || i - prevIdx > currentLength)
            ++currentLength;
        else {
            //出现重复字符
            maxLength = max(currentLength, maxLength);
            // 子串重新截断成为上一个char str[prevIdx[后的字符到str[i]的字符，即str[prevIdx+1,i],闭区间
            currentLength = i - prevIdx;
        }
        position[str[i] - 'a'] = i; //更新最新的位置
    }
    ///一组字符串可能到最后可能到最后都没有重复的
    maxLength = max(maxLength, currentLength);
    return maxLength;
}
