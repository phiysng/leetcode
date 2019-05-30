// 38 字符串的排列
// ⭐⭐⭐⭐⭐
// 有点难理解
#include "array_util.h"
using namespace std;

void Permutation(char* pStr)
{
    if (pStr == nullptr)
        return;
    Permutation(pStr, pStr);
}

void Permutation(char* pStr, char* pBegin)
{
    if (*pBegin == '\0') {
        printf("%s\n", pStr);
    } else {
        for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
            // swap
            char c = *pCh;
            *pCh = *pBegin;
            *pBegin = c;
            Permutation(pStr, pBegin + 1);

            // swap back
            c = *pCh;
            *pCh = *pBegin;
            *pBegin = c;
        }
    }
}
