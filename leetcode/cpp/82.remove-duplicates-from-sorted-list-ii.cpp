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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* _head = head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* cur = dummy;
        
        while(cur->next && cur->next->next){
            //删除后两个节点重复的第二个 
            //然后继续上述过程 如果后两个节点依然重复
            if(cur->next->val == cur->next->next->val){
                while(cur->next && cur->next->next && cur->next->val == cur->next->next->val){
                    cur->next->next = cur->next->next->next;
                }
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        
        
        return dummy->next;
    }
};
