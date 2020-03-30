#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题24. 反转链表

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
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            auto next_node = curr->next;
            curr->next = prev;
            prev = curr;

            curr = next_node;
        }

        return prev;
    }
};
