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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        auto p = head;
        //首部的重复元素
        while (p->next) {
            if (p->val == p->next->val)
                p = p->next;
            else
                break;
        }
        //p指向第一个非重复的元素
        if (!p->next || !p->next->next)
            return p;
        auto res = p;
        while (p->next->next) {
            if (p->next->val == p->next->next->val) {
                p->next = p->next->next;
                //free p->next 当然此时已经失去了对他的引用 Memory Leak -_-
                // if(!p->next->next){//如果只剩下两个节点需要返回
                //     break;
                // }
            } else
                p = p->next;
        }
        return res;
    }
};