import java.util.ArrayList;

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        UnionFind unionFind = new UnionFind(edges.length);
        var r = new ArrayList<ArrayList<Integer>>();
        for (int i = 0; i < edges.length; i++) {
            if (unionFind.connected(edges[i][0], edges[i][1])) {
                var t = new ArrayList<Integer>();
                t.add(edges[i][0]);
                t.add(edges[i][1]);
                r.add(t);
            } else {
                unionFind.Union(edges[i][0], edges[i][1]);
            }
        }
        return r.get(r.size() - 1).stream().mapToInt(i -> i).toArray();
    }

    class UnionFind {
        public UnionFind(int _size) {
            this.size = _size;
            parents = new ArrayList<>(_size);
            for (int i = 0; i < _size + 1; i++) {
                parents.add(i);
            }
        }

        public void Union(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                parents.set(rootJ, rootI);
            }
        }

        public boolean connected(int i, int j) {
            return find(i) == find(j);
        }

        public int find(int id) {
            int _id;
            while ((_id = parents.get(id)) != id) {
                id = _id;
            }
            ;
            return id;
        }

        int size;
        private ArrayList<Integer> parents;
    }
}
