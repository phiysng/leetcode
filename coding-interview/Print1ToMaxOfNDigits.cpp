/// 17 打印从1到最大的n位数

/// 大数问题 用数组模拟

#include "array_util.h"
using namespace std;

// 不输出开头的空格
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int len = strlen(number);
    for (int i = 0; i < len; ++i) {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 - false;

        if (!isBeginning0) {
            printf("%c", number[i]);
        }
    }
    printf("\t");
}

bool Increment(char* number)
{
    bool isOverflow = false;
    int nTakeOver = 0;

    int nLength = strlen(number);

    for (int i = nLength - 1; i >= 0; --i) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum++;
        if (nSum >= 10) {
            if (i == 0) {
                isOverflow = true;
            } else {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        } else {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverflow;
}

void Print1ToMaxOfNDigits(int n)
{
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    memset(number, '0', n);

    number[n] = '\0';

    while (!Increment(number)) {
        PrintNumber(number);
    }
    delete[] number;
}

// 递归解法
// 排列组合 某种意义上的深度优先遍历
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1) {
        PrintNumber(number);
        return;
    }

    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_recursive(int n)
{
    if (n <= 0)
        return;
    char* number = new char[n + 1];
    memset(number, '0', n);

    number[n] = '\0';

    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
}
