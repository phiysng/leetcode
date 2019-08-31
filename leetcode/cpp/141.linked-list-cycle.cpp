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
    bool hasCycle(ListNode* head)
    {
        if (!head || !head->next)
            return false;

        auto quick = head->next;

        while (head && quick) {
            head = head->next;

            if (quick->next == nullptr) {
                return false;
            }
            quick = quick->next->next;

            if (head != nullptr && head == quick)
                return true;
        }

        return false;
    }
};
