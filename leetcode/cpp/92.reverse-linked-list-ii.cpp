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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        //待逆置的链表的前一个结点
        ListNode *prev = dummy;

        for (int i = 0; i < m - 1; ++i)
        {
            prev = prev->next;
        }
        //待逆置的链表的最后一个结点
        ListNode *last = prev;

        int distance = n - m + 1;
        for (int i = 0; i < distance; ++i)
        {
            last = last->next;
        }
        //待逆置的链表的后一个结点 用于重新串起逆置后的链表
        ListNode *node = last->next;
        //断开待逆置的链表
        last->next = nullptr;

        // 子链表原表头 逆置后链表尾
        auto init_part_head = prev->next;
        //逆置后的链表头
        auto part_head = reverse(prev->next);

        //串起逆转后的链表
        prev->next = part_head;
        init_part_head->next = node;

        return dummy->next;
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
