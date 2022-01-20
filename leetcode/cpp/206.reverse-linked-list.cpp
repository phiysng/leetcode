#include "oj_header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        auto rest = reverseList(head->next); //反转后n-1个链表
        head->next->next = head;
        /// \note 反转后的链表的尾结点应当指向 `nullptr`
        head->next = nullptr;

        return rest;
    }
};
