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
    ListNode* insertionSortList(ListNode* head) {
        // 对于[1,n)插入第一个大于他的元素前
        // 注意有可能会成为新的头节点
        
        if(!head || !head->next) return head; 
        
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy; //每次从链表头开始遍历
        ListNode* curr = head; //当前待插入的节点
        
        while(curr && curr->next){
            //后继节点小于当前的节点 需要位这个后继节点寻找一个合适的插入位置
            if(curr->next->val < curr->val){
                while(prev->next->val < curr->next->val){
                    prev = prev->next;
                }
                //将此节点插入到这个位置上来
                auto t = prev->next; //插入后需要连上的节点
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = t;
                
                prev = dummy;
                
            }
            else
            {
                curr = curr->next;
            }
        }
        
        return dummy->next;
    }
};
