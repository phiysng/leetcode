import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

/**
 * 在没下雨的那一天就要决定进行抽水 
 * 否则如果遇到满的湖再次下雨再决定没下雨的那天抽那个湖就需要处理时间区间上的问题
 */
class Solution {
    public int[] avoidFlood(int[] rains) {

        List<Integer> r = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        Map<Integer, LinkedList<Integer>> map = new HashMap<>();

        // n号湖哪些天会下雨
        for (int i = 0; i < rains.length; i++) {
            if (map.containsKey(rains[i])) {
                map.get(rains[i]).add(i);
            } else {
                var list = new LinkedList<Integer>();
                list.add(i);
                map.put(rains[i], list);
            }
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int i = 0; i < rains.length; i++) {
            if (rains[i] > 0) {
                // 当前的湖这一天要下雨
                // 已满的湖没有办法
                if (set.contains(rains[i])) {
                    return new int[0];
                } else {

                    set.add(rains[i]);
                    var days = map.get(rains[i]);
                    days.removeFirst();
                    // 将未来的下雨时间加入队列 (如果存在)
                    if (!days.isEmpty()) {
                        // index of day
                        pq.add(days.getFirst());
                    }
                }
                r.add(-1);
            } else {
                // 这一天可以抽水
                // 没有已满的湖 可以随意操作
                if (pq.isEmpty()) {
                    r.add(1);
                } else {
                    // 抽出已满的湖中最近要下雨的湖的水
                    int idx = pq.poll();
                    set.remove(rains[idx]);
                    r.add(rains[idx]);
                }
            }
        }
        return r.stream().mapToInt(i -> i).toArray();
    }
}
