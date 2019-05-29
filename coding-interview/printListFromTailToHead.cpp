/// 面试题6 从尾到头打印链表

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

/// 同样可以基于递归实现 代码更易于理解
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> res;
        while (head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};