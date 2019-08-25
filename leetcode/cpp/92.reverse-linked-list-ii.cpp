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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (!head)
            return head;

        ListNode *curr = head, *prev = nullptr;

        // 找到要翻转的位置
        while (m > 1) {
            prev = curr;
            curr = curr->next;
            --m;
            --n;
        }

        //  翻转子链表
        ListNode *conn = prev, *tail = curr;

        ListNode* t = nullptr;

        while (n > 0) {
            t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
            --n;
        }

        // 到最后prev指向原本子链表的最后一个节点 反转后链表的第一个节点
        // curr则指向后面的第一个没有被翻转的节点(有可能为NULL)

        // 如果是从头节点开始翻转
        // conn保存着反转节点前面的一个节点 而 tail指向原来的子链表的表头 反转后的表位
        if (conn == nullptr) {
            head = prev;
        } else {
            conn->next = prev;
        }

        //原本子链表的表头作为现在的表位
        tail->next = curr;

        return head;
    }
};
