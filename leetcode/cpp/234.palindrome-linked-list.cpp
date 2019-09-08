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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        
        auto mid_node = getMiddle(head);
        
        auto res = reverse(mid_node);
        
        auto curr = head;
        while(curr && curr != mid_node){
            if(curr->val != res->val){
                return false;
            }
            curr = curr->next;
            res = res->next;
        }
        return true;
        
        
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    ListNode* getMiddle(ListNode* head){
        auto slow = head;
        auto fast = head->next;
        
        while(slow && fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            else{
                break;
            }
        }
        return slow;
    }
};
