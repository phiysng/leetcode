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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode* odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode *currOdd = odd, *currEven = even;

        while (head) {
            currOdd->next = head;
            head = head->next;
            currOdd = currOdd->next;
            if (head) {
                currEven->next = head;
                currEven = currEven->next;
                head = head->next;
            }
        }

        // 如果是奇数个链表 那偶数号最后一个节点还指向奇书的链表那里，将其指向nullptr
        currEven->next = nullptr;
        currOdd->next = even->next;
        return odd->next;
    }
};
