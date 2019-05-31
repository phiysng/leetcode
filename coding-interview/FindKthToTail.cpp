// 22 链表中倒数第k个节点

#include "array_util.h"
using namespace std;


/// 指针操作注意nullptr

ListNode* FindKthToTail(ListNode* head, int k)
{
    if (!head || k <= 0)
        return nullptr;

    // 快慢指针
    ListNode* ahead = head;
    ListNode* behind = nullptr;

    for (int i = 0; i < k - 1; ++i) {
        if (ahead->next) {
            ahead = ahead->next;

        } else {
            return nullptr;
        }
    }

    behind = head;
    //  1 2 3 4
    //    ⬆
    // 最后 ⬆ ⬆
    // 倒数第二个
    //
    // 当快指针到达最后一个节点
    while (ahead->next) {
        ahead = ahead->next;
        behind = behind->next;
    }
    return behind;
}
