/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        if (head == null)
            return null;

        var prev : ListNode? = null
        var curr = head
        while (curr != null) {
            // we need to save the pointer to the next iteration
            val next = curr.next
            curr.next = prev
            // curr is the new prev node that need to be pointed to
            prev = curr
            curr = next
        }

        return prev
    }
}