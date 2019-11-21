/**
 * Definition for singly-linked list.
 * class ListNode(var _x: Int = 0) {
 *   var next: ListNode = null
 *   var x: Int = _x
 * }
 */
object Solution {
  def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
    var carry = false
    val dummy = new ListNode(-1)
    var _l1 = l1
    var _l2 = l2
    var curr = dummy
    
    while (carry || _l1 != null || _l2 != null) {
      var t = 0
      if (_l1 != null) {
        t += _l1.x
        _l1 = _l1.next
      }

      if (_l2 != null) {
        t += _l2.x
        _l2 = _l2.next
      }

      if (carry) {
        t += 1
        carry = false
      }
      
      if(t >= 10){
        t %= 10
        carry = true
      }
      curr.next = new ListNode(t)
      curr = curr.next

    }
    dummy.next
  }
}