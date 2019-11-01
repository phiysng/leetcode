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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *last = head; //待翻转的最后一个结点
        for (int i = 0; i < k - 1; ++i)
        {
            //当前的结点不能是最后一个结点 才能向后 last不可以为nullptr 为nullptr说明剩余的结点数量不够一次翻转
            if (last && last->next)
                last = last->next;
            else
                return head;
        }
        //断开的第一个节点
        auto t = last->next;
        last->next = nullptr;

        //翻转后的头节点
        auto rev = reverse(head);

        auto res = reverseKGroup(t, k);
        head->next = res;

        return rev;
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *prev = nullptr;

        while (head)
        {
            auto next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }

        return prev;
    }
};
