// 24 反转链表

#include "array_util.h"
using namespace std;

ListNode* ReverseList(ListNode* head)
{
    ListNode* prev = nullptr; //链表的结尾
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        /// ⭐⭐⭐顺序很重要 颠倒会导致prev指向原next
        prev = curr;
        curr = next;
    }
    return prev;
}
