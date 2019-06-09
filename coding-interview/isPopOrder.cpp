// 31 栈的压入弹出序列

// 使用一个栈来模拟
// 1. 当当前的栈顶恰好是这个数字时 出栈
// 2. 否则入栈 直到栈顶恰好是这个数组 
//    如果所有的数字均已入栈还是无法满足 则返回false

#include "array_util.h"
using namespace std;

// 实现比较有意思

bool isPopOrder(const int* push, const int* pop, int length)
{
    bool possible = false;
    if (!push || !pop || length <= 0)
        return possible;

    const int* nextPush = push;
    const int* nextpop = pop;

    stack<int> stackData;

    while (nextpop - pop < length) {
        // 找到压入下一个相等的数字
        // 当前的top == *nextpop相等跳过 直接出栈
        while (stackData.empty() || stackData.top() != *nextpop) {
            if (nextPush - push == length)
                break;
            stackData.push(*nextPush);
            ++nextPush;
        }

        // 不合法 没有可能的出栈顺序
        if (stackData.top() != *nextpop) {
            break;
        }

        stackData.pop();
        nextpop++;
    }
    // 恰好栈空且匹配 pop 出的所有数字
    if (stackData.empty() && nextpop - pop == length)
        possible = true;

    return possible;
}
