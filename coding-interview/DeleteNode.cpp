/// 18 删除链表的节点
/// O(1)时间的删除 由调用者保证正确性
struct ListNode
{
    int val;
    ListNode *next;
};

class Solution
{
public:
    void DeleteNode(ListNode **head, ListNode *pToBeDeleted)
    {
        if (!head || !pToBeDeleted)
            return;
        //待删除结点不是尾节点
        if (pToBeDeleted->next != nullptr)
        {
            /// 复制下一节点的值 并删除下一节点
            /// 此节点存在 且不为尾节点
            ListNode *next = pToBeDeleted->next;
            pToBeDeleted->val = pToBeDeleted->next->val;
            pToBeDeleted->next = pToBeDeleted->next->next;

            // 在LeetCode中不要这样做，不要尝试释放内存，会触发内存访问错误
            delete next;
            next = nullptr;
        }
        else if (*head == pToBeDeleted)
        {
            /// 只有头节点的情况
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *head = nullptr;
        }
        else
        {
            /// 链表中有多个节点 删除尾节点的情况
            ListNode *curr_node = *head;
            /// 正常的从头遍历至倒数第二个节点
            while (curr_node->next != pToBeDeleted)
            {
                curr_node = curr_node->next;
            }
            curr_node->next = nullptr;
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
};
