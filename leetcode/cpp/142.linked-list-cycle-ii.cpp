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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr;

        auto slow = head;
        auto fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (!slow || !fast || !fast->next)
        {
            return nullptr;
        }

        // 获得交点
        auto r = head;
        while (slow != r)
        {
            r = r->next;
            slow = slow->next;
        }

        return slow;
    }
};