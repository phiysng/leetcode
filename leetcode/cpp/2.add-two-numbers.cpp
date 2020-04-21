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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!11)
            return l2;
        if (!l2)
            return l1;
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        bool flag = false; //是否进位
        ListNode *p1 = l1, *p2 = l2;
        int sum = 0;
        while (p1 || p2 || flag) {
            sum = flag;
            if (p1) {
                sum += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                sum += p2->val;
                p2 = p2->next;
            }
            p->next = new ListNode(sum % 10);
            p = p->next;
            flag = sum / 10;
        }

        return head->next;
    }
};
