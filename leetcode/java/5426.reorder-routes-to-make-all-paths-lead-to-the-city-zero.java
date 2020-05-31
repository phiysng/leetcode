import java.util.HashSet;

class Solution {
    public int minReorder(int n, int[][] cons) {
        int count = 0;
        HashSet<Integer> set = new HashSet<>();
        set.add(0);
        while (set.size() < n) {
            for (int[] pair : cons) {
                // 向量的终点在可达集合中 那么起点肯定也在
                if (set.contains(pair[1])) {
                    set.add(pair[0]);
                } else if (set.contains(pair[0])) {
                    // 终点不在集合中 但是起点在 说明是朝外指向的向量
                    // TODO: 证明直接翻转的正确性
                    set.add(pair[1]);
                    count += 1;
                }
            }
        }
        return count;
    }
}
