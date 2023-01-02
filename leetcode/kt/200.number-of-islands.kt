class Solution {
    fun numIslands(grid: Array<CharArray>): Int {
        if (grid.isEmpty()) return 0
        val m = grid.size
        if (grid[0].isEmpty()) return 0
        val n = grid[0].size

        val disJointSet = DisJointSet(m, n)

        // in the begining, all land node point to self
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (grid[i][j] == '1') {
                    disJointSet.addRoot(i, j)
                }
            }
        }

        // scan all land node
        for (i in 0 until m) {
            for (j in 0 until n) {
                val isLand = grid[i][j] == '1'
                if (!isLand) continue
                // look right
                if (j < n - 1) {
                    val isRightLand = grid[i][j + 1] == '1'
                    if (isRightLand) {
                        // point to this very node
                        disJointSet.union(i, j, i, j + 1)
                    }
                }

                // look down
                if (i < m - 1) {
                    val isDownLand = grid[i + 1][j] == '1'
                    if (isDownLand) {
                        disJointSet.union(i, j, i + 1, j)
                    }
                }
            }
        }

        return disJointSet.count()
    }
}