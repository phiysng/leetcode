/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ComapreNode{
public:
    ComapreNode(){}
    bool operator()(ListNode* a , ListNode*b){return a->val < b->val;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         priority_queue<ListNode*,vector<ListNode*>,ComapreNode> pq;
         for(auto i : lists){
             while(i){
                 pq.push(i);
                 i = i->next;
             }

         }
         ListNode* res = nullptr;
         while(!pq.empty()){
             auto p = pq.top();
             p->next = res;
             res = p;
             pq.pop();
         }
         return res;
    }
};
