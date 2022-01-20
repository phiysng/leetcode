#include "oj_header.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        //快慢指针
        // 注意头节点被删除的特殊情况

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;
        //题目保证数据有效
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};
