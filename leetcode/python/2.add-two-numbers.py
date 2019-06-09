# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        p = l1
        q = l2
        curr = dummyHead
        carry = 0
        # 链表没结束
        while p or q or carry:
            x = p.val if p else 0
            y = q.val if q else 0
            sum = x + y + carry

            carry = sum // 10
            curr.next = ListNode(sum % 10)
            curr = curr.next

            if p:
                p = p.next
            if q:
                q = q.next
        return dummyHead.next
