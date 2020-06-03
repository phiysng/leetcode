import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.HashSet;
import java.util.LinkedList;

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

// BFS solution
class Solution_BFS {
    public int minReorder(int n, int[][] cons) {
        List<List<List<Integer>>> g = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        // 邻接表 每一个结点所指向的结点
        for (var c : cons) {
            // 指出去的需要翻转
            g.get(c[0]).add(List.of(c[1], 1));
            // 指向自己的不需要翻转
            g.get(c[1]).add(List.of(c[0], 0));
        }

        int ans = 0;
        var queue = new LinkedList<Integer>();
        queue.add(0);
        
        //ref: https://stackoverflow.com/questions/5600668/how-can-i-initialize-an-arraylist-with-all-zeroes-in-java
        List<Integer> seen = new ArrayList<>(Collections.nCopies(n + 1, 0));

        // BFS from node 0.
        while (!queue.isEmpty()) {
            int curr = queue.getFirst();
            queue.pop();
            seen.set(curr, 1);
            // traverse all node it point to.
            for (var pair : g.get(curr)) {
                if (seen.get(pair.get(0)) == 1) {
                    continue;
                }
                // destination not accessible, so add flip costs
                ans += pair.get(1);
                // add to next iteration.
                queue.push(pair.get(0));
            }
        }

        return ans;
    }
}
