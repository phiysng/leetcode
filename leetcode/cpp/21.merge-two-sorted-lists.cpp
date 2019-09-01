/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution_recursive {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode* dummy = new ListNode(-1);

        ListNode* current = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            } else {
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }
        if (l1) {
            current->next = l1;
        }

        if (l2) {
            current->next = l2;
        }
        return dummy->next;
    }
};
