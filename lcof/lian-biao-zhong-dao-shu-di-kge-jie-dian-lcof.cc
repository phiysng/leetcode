#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题22. 链表中倒数第k个节点

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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        // using fast/slow ptr.
        
        ListNode* fast_ptr = head;
        // we expect the list is long enough.
        for(int i = 0 ; i < k; ++i){
            fast_ptr = fast_ptr->next;
        }
        
        ListNode* slow_ptr = head;
        while(fast_ptr){
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
        }

        return slow_ptr;
    }
};
