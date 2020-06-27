import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

/**
 * 其他人的解法真的快
 * 在没下雨的那一天就要决定进行抽水 否则如果遇到满的湖再次下雨再决定没下雨的那天抽那个湖就需要处理时间区间上的问题 
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

/**
 * 原来的思路 在湖满之后再下雨才处理之前的抽水 二分查找
 */
class Solution_v2 {
    public int[] avoidFlood(int[] rains) {
        List<Integer> drains = new LinkedList<>();
        List<Integer> r = new ArrayList<>();
        Set<Integer> set = new HashSet<>();
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < rains.length; i++) {
            if (rains[i] > 0) {
                if (set.contains(rains[i])) {
                    if (drains.isEmpty()) {
                        return new int[0];
                    }

                    int idx = map.get(rains[i]);
                    System.out.println(idx);
                    int rcode = binarySearch(drains, idx);
                    if (rcode == -1) {
                        return new int[0];
                    }
                    r.set(drains.get(rcode), rains[i]);
                    drains.remove(rcode);

                } else {
                    // 之前为空湖
                    set.add(rains[i]);
                }
                r.add(-1);
                map.put(rains[i], i);
            } else {
                drains.add(i);
                r.add(1);
            }
        }
        return r.stream().mapToInt(i -> i).toArray();
    }

    private static int BruteForceSearch(List<Integer> list, int limit) {
        if (list.get(0) > limit)
            return 0;
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) < limit && list.get(i + 1) > limit)
                return i + 1;
        }
        return -1;
    }

    private static int binarySearch(List<Integer> list, int limit) {

        int l = 0;
        int r = list.size();
        if (list.isEmpty())
            return -1;
        if (list.size() == 1) {
            return list.get(0) > limit ? 0 : -1;
        }

        if (list.get(0).compareTo(limit) > 0)
            return 0;

        if (list.get(r - 1).compareTo(limit) < 0)
            return -1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (mid == 0 && list.get(mid).compareTo(limit) < 0 && list.get(mid + 1).compareTo(limit) > 0)
                return 1;

            if (mid == r - 1 && list.get(mid).compareTo(limit) > 0 && list.get(mid - 1).compareTo(limit) < 0)
                return mid;

            if (list.get(mid).compareTo(limit) < 0 && mid + 1 < r && list.get(mid + 1).compareTo(limit) > 0) {
                return mid + 1;
            }
            if (list.get(mid).compareTo(limit) < 0 && mid + 1 < r && list.get(mid + 1).compareTo(limit) < 0) {
                l = mid + 1;
            }
            if (list.get(mid).compareTo(limit) > 0 && mid + 1 < r && list.get(mid + 1).compareTo(limit) > 0) {
                r = mid + 1;
            }

        }

        return -1;
    }
}
