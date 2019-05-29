// 50 第一个只出现一次的字符

#include "array_util.h"
using namespace std;

// 两次遍历 第一次统计数量 第二次找到第一个不重复的单词
char FirstNotRepeatingChar(const string& s)
{
    // 错误处理 真的合适吗😔
    if (s.length() == 0)
        return '\0';
    const int tableSIze = 256;
    int hashTable[tableSIze] = { 0 };
    for (char c : s) {
        hashTable[c]++;
    }
    for (char c : s) {
        if (hashTable[c] == 1) {
            return c;
        }
    }
    return '\0';
}

/// 相关题目2
class Solution {
public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        arr[ch]++;
        v.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for (int i = 0; i < v.size(); ++i) {
            if (arr[v[i]] == 1)
                return v[i];
        }
        return '#';
    }

private:
    char arr[256] = { 0 };
    vector<char> v;
};

/// 原来的实现 很精妙 结合了 char的大小创建简单的哈希表 && 特殊下标表示含义
///在这里有3种下标
/// -1 未出现该字符
/// -2 出现2次及以上
///[0,∞) 只出现一次的字符

class CharStatistics {
public:
    CharStatistics()
        : index(0)
    {
        for (int i = 0; i < 256; ++i)
            occurrence[i] = -1;
    }

    void Insert(char ch)
    {
        if (occurrence[ch] == -1)
            occurrence[ch] = index;
        else if (occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++; //标识字符所出现的顺序
    }

    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for (int i = 0; i < 256; ++i) {
            // 遍历哈希表找出index最小的同时只出现一次的char
            if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }

private:
    // occurrence[i]: A character with ASCII value i;
    // occurrence[i] = -1: The character has not found;
    // occurrence[i] = -2: The character has been found for mutlple times
    // occurrence[i] >= 0: The character has been found only once
    int occurrence[256];
    int index;
};
