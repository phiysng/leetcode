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
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        
        return quickSort(head,nullptr);
    }
    /// 链表版本的快速排序 维护三条子链表
    /// 大于头节点的值的链表 || 等于 || 小于
    ListNode* quickSort(ListNode* head, ListNode* end){
        // partition后的大于头节点和小于头节点的子链表
        ListNode* sentryLeft = new ListNode(0), * sentryRight = new ListNode(0);
		//        用于添加新节点的临时指针          另一个         中间节点(会将值相同的节点都挂在这个节点后面)  原始的
        //中间节点 用于被连接到左边链表的后面
        ListNode* left = sentryLeft, * right = sentryRight, * mid = head, * midOri = head;
    
        //单链表的时候跳过
        while(head->next != end){
            head = head->next;
            
            // 选择添加到左边链表 中间 还是右边
            if(mid->val > head->val){
                //添加到当前链表表尾
                left->next = head;
                left = head;
            }else if(mid->val < head->val){
                right->next = head;
                right = head;
            }
            else{
                mid->next = head;
                mid = head;
            }
        }
        // 此时链表被分为三条子链表
        
        if(sentryRight->next){
            right->next = end; //连接到当前的链表所在的父链表的右边
            mid->next =  quickSort(sentryRight->next,end);
        }
        else{
            mid->next = end;
        }
        
        if(sentryLeft->next){
            left->next = midOri; //连接到中间链表的表头
            return quickSort(sentryLeft->next,midOri);
        }
        else{
            //左边为空 则从中间链表的表头开始 
            //右边的链表如果存在 已经被链接到了中间链表的表尾
            return midOri;
        }
        
    }
};
