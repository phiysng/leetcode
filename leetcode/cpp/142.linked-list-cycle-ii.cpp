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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        
        auto slow = head;
        auto fast = head->next;
        
        while(slow && fast){
            if(slow == fast)
                break;
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            
        }
        if(!slow || !fast){
            return nullptr;
        }
        
        // 获得交点
        slow = slow->next;
        auto r = head;
        while(slow != r){
            r = r->next;
            slow = slow->next;
        }
        
        return slow;
    }
};