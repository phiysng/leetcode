// 58 翻转字符串
// 另见 LeetCode 151

#include "array_util.h"
using namespace std;

void Reverse(char* pBegin, char* pEnd)
{
    if (!pBegin || !pEnd)
        return;

    while (pBegin < pEnd) {
        char t = *pBegin;
        *pBegin = *pEnd;
        *pEnd = t;

        pBegin++;
        pEnd--;
    }
}

char* ReverseSentence(char* pData)
{
    if (pData == nullptr)
        return nullptr;

    char* pBegin = pData;
    char* pEnd = pData;

    while (*pEnd != '\0')
        ++pEnd;
    pEnd--;

    // 翻转整个句子
    Reverse(pBegin, pEnd);

    // 翻转句子中的每个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0') {
        //跳过空格
        if (*pBegin == ' ') {
            pBegin++;
            pEnd++;
        } else {
            //圈出两个空格之间的部分 并反转
            if (*pEnd == ' ' || *pEnd == '\0') {
                Reverse(pBegin, --pEnd);
                pBegin = ++pEnd;
            } else {
                // 继续寻找单词的结束位置
                ++pEnd;
            }
        }
    }
    return pData;
}

/// 在牛客网上通过的实现
string ReverseSentence(string str)
{
    string res = "", t = "";
    for (auto c : str) {
        if (c == ' ') {
            //空格 将串联起来
            res = " " + t + res;
            t = "";
        } else {
            t += c;
        }
    }
    if (t.size()) //C非空 即str不以空格结尾时
        res = t + res;

    return res;
}

/// 左旋转字符串
/// 三次旋转 abcdefg -> ba_gfedc ->cdefgab
char* LeftRotateString(char* pStr, int n)
{
    if (pStr) {
        int nLength = static_cast<int>(strlen(pStr));
        if (nLength > 0 && n > 0 && n < nLength) {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;

            // 翻转前n个
            Reverse(pFirstStart, pFirstEnd);
            // 翻转后面的部分
            Reverse(pSecondStart, pSecondEnd);
            //翻转整体
            Reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}
