// 52 两个链表的第一个公共节点

#include "array_util.h"
using namespace std;

int GetListLength(ListNode* head)
{
    int len = 0;
    while (head != nullptr) {
        ++len;
        head = head->next;
    }
    return len;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    int len1 = GetListLength(pHead1);
    int len2 = GetListLength(pHead2);

    //两个链表长度之差 ☞
    int distance = len1 - len2;

    ListNode* longList = pHead1;
    ListNode* shortList = pHead2;

    if (len2 > len1) {
        swap(longList, shortList);
        distance = -distance;
    }

    //长链表移动到长度相同的位置
    for (int i = 0; i < distance; i++) {
        longList = longList->next;
    }

    //同时移向下一个节点直到到达第一个公共节点
    while (longList != nullptr && shortList != nullptr && longList != shortList) {
        longList = longList->next;
        shortList = shortList->next;
    }
    return longList;
}
