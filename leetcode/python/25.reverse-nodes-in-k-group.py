# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


'''
递归的解法
只需对链表进行一次遍历
递归层次O(n/k)
'''


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        if not head:
            return head

        # prev k 个一组的最后一个结点
        # curr k 个一组的下一组的第一个结点
        prev = None
        curr = head

        not_enough = False

        for i in range(k):
            # 是否有足够的数量进行下一次翻转
            # 如例子中的k = 3时
            # 第一次有足够的数量 第二次就不够了
            if(not curr):
                not_enough = True
                break
            prev = curr
            curr = curr.next
        prev.next = None  # 断开链表

        if(not not_enough):
            # 有多余的链表时翻转前一段链表并递归调用此函数
            rev_head = self.reverseList(head)
            head.next = self.reverseKGroup(curr, k)
        else:
            # 不足时不翻转 直接返回
            return head

        return prev

    # 单链表逆置
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None

        while head:
            next = head.next
            head.next = prev

            prev = head
            head = next
        return prev


'''
迭代版本
维护两个指针
一个指向k个链表的前一个结点
一个指向k个链表的后一个结点
'''


class Solution_v2:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head

        dummy = ListNode(-1)
        dummy.next = head

        prev = dummy
        curr = head

        while curr:
            ptr = prev
            for i in range(k):
                if not ptr:
                    break
                else:
                    ptr = ptr.next
            # if prev == None , we can assert that
            # there is no enough node for this iteration
            if not ptr:
                break
            """
            
            """
            ttttt = prev.next
            curr = ptr.next  # 下一段的开始
            ptr.next = None  # break list into two parts
            new_head = self.reverseList(prev.next)  # reverse the prev part

            prev.next.next = curr  # connect to latter part
            prev.next = new_head  # connect to the prev part

            prev = ttttt

        return dummy.next

    # 单链表逆置
    def reverseList(self, head: ListNode) -> ListNode:
        prev = None

        while head:
            next = head.next
            head.next = prev

            prev = head
            head = next
        return prev
