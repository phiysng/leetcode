# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        dummy = ListNode(-1)
        dummy.next = head

        prev = dummy

        while prev and prev.next and prev.next.next:
            curr = prev.next
            back = curr.next.next

           # 断开链表
            curr.next.next = None
            prev.next = self.reverseList(curr)
            curr.next = back

            prev = curr
        return dummy.next

    def reverseList(self, head: ListNode) -> ListNode:
        prev = None
        while head:
            next = head.next
            head.next = prev

            prev = head
            head = next

        return prev
