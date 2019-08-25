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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if( k == 0 ) return head;
        
        ListNode *_head = head;
        
        int len = 1;
        while(_head->next){
            _head = _head->next;
            ++len;
        }
        //cout << len <<endl;
        //连成环
        _head->next = head;
        
        //从头节点走k步 然后断开连接
        k = k % len;
        int ite = len - k;
        ListNode* prev = nullptr;
        for(int i = 0; i < ite ;++i){
            prev = head;
            head = head->next;
        }
        
        ListNode* real_head = head;
        
        prev->next = nullptr;
        
        return real_head;
        
        
    }
};
