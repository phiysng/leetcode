// 25 合并两个排序的链表
// 另参见 LeetCode 21

// 本题也有迭代的写法

#include "array_util.h"
using namespace std;

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;

    ListNode* pMergedHead = nullptr;

    if (pHead1->val < pHead2->val) {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    } else {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergedHead;
}
