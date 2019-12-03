
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>(Comparator.comparing((a) -> a.val));

        for (ListNode list : lists)
            if (list != null) {
                pq.add(list);

            }

        ListNode dummy = new ListNode(-1);
        ListNode head = dummy;
        while (!pq.isEmpty()) {
            ListNode t = pq.poll();
            head.next = t;
            head = head.next;
            if (t.next != null)
                pq.offer(t.next);
        }

        return dummy.next;
    }
}

/**
 * 下面的做法是不合适的: 将所有的结点都放入一个pq.
 */
class Pair<F, S> {
    public Pair(F f, S s) {
        this.first = f;
        this.second = s;
    }

    public F first;
    public S second;
}

class Solution_wrong {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Pair<Integer, ListNode>> pq = new PriorityQueue<Pair<Integer, ListNode>>(
                Comparator.comparing((Pair<Integer, ListNode> a) -> a.first));

        for (ListNode list : lists)
            while (list != null) {
                pq.add(new Pair<>(list.val, list));
                list = list.next;
            }

        ListNode dummy = new ListNode(-1);
        ListNode head = dummy;
        while (!pq.isEmpty()) {
            head.next = pq.peek().second;
            head = head.next;
            pq.poll();
        }

        return dummy.next;
    }
}
