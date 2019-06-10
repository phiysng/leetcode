# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        '''
        17 和 21行的后一个检查在此题中是多余的
        因为题目保证数据有效
        这道题目的问题一方面是快慢指针
        另一方面是注意待删除的节点是头节点的情况
        '''
        dummy = ListNode(-1)
        dummy.next = head
        
        fast = slow = dummy
        
        while n and fast:
            fast = fast.next
            n -= 1
        
        while fast.next and slow.next:
            fast = fast.next
            slow = slow.next
            
        slow.next = slow.next.next
        
        return dummy.next