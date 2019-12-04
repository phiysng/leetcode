/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        ListNode dummy = new ListNode(-1);
        ListNode head = dummy;

        boolean carry = false;
        while (l1 != null || l2 != null || carry) {
            int n = 0;
            if (l1 != null) {
                n += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                n += l2.val;
                l2 = l2.next;
            }
            if (carry) {
                n++;
            }

            carry = n >= 10;
            n %= 10;

            head.next = new ListNode(n);
            head = head.next;

        }

        return dummy.next;
    }
}
