// 23 链表中环的入口节点
// TODO: 数学证明
#include "array_util.h"
using namespace std;

ListNode* MeetingNode(ListNode* pHead)
{
    if (pHead == nullptr)
        return nullptr;

    ListNode* pSlow = pHead->next;
    if (pSlow == nullptr)
        return nullptr;
    ListNode* pFast = pSlow->next;
    while (pSlow && pFast) {
        if (pFast == pSlow)
            return pFast;

        pSlow = pSlow->next;

        pFast = pFast->next;
        /// 防止 **NULL** 指针的解引用
        if (pFast)
            pFast = pFast->next;
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode = MeetingNode(pHead);

    if (!meetingNode)
        return nullptr;

    ///得到环中节点的数目
    int nodesInLoop = 1;
    ListNode* pNode1 = meetingNode;
    while (pNode1->next != meetingNode) {
        pNode1 = pNode1->next;
        ++nodesInLoop;
    }

    /// 先移动一个指针
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; i++) {
        pNode1 = pNode1->next;
    }

    ListNode* pNode2 = pHead;
    while (pNode1 != pNode2) {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}
