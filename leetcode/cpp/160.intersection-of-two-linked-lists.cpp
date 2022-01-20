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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        // 遍历两遍 从而使得路程相同 在这种情况下如果有交点就一定会是同步的
        auto t1 = headA;
        auto t2 = headB;

        bool b1 = true, b2 = true;

        while (t1 && t2) {
            if (t1 == t2)
                return t1;

            t1 = t1->next;
            if (!t1 && b1) {
                t1 = headB;
                b1 = false;
            }
            t2 = t2->next;
            if (!t2 && b2) {
                t2 = headA;
                b2 = false;
            }
        }

        return nullptr;
    }
};
