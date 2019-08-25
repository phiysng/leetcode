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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        
        //反转后的表头肯定时第二个元素
        ListNode* res = head->next;
        
        //两两反转
        ListNode *curr = head->next;
        ListNode *prev = head;
        
        //需要前一个节点的指针将反转后的链表与前面的链表连接起来
        ListNode* conn = nullptr;
        //当两个节点都存在时
        while( curr && prev )
        {
            ListNode *t = curr->next;
            curr->next = prev;
            prev->next = t;
            if(conn){
                conn->next = curr;
                conn = prev;
            }
            else{
                conn = prev;
            }
            prev = t;
            
            if(prev)
                curr = t->next;
            
        }
        
        return res ? res : head;
    }
};