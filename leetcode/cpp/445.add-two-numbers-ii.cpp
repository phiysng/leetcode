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
        ListNode* rl1 = reverseList(l1);
        ListNode* rl2 = reverseList(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        auto curr = dummy;
        while (rl1 || rl2 || carry) {
            int t = 0;
            if (rl1) {
                t += rl1->val;
                rl1 = rl1->next;
            }

            if (rl2) {
                t += rl2->val;
                rl2 = rl2->next;
            }
            if (carry) {
                ++t;
                carry = 0;
            }

            carry = t / 10;
            curr->next = new ListNode(t % 10);
            curr = curr->next;
        }
        return reverseList(dummy->next);
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;

        while (head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};
