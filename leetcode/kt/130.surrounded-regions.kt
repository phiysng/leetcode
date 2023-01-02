class Solution {
    companion object {
        val O = 'O'
        val X = 'X'
    }

    fun solve(board: Array<CharArray>): Unit {
        if (board.isEmpty()) return
        if (board[0].isEmpty()) return
        val m = board.size
        val n = board[0].size
        val disJointSet = DisJointSet(m, n)
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (board[i][j] == O) {
                    disJointSet.addRoot(i, j)
                }
            }
        }

        // merge O nodes
        for (i in 0 until m) {
            for (j in 0 until n) {
                val isLand = board[i][j] == O
                if (!isLand) continue
                // look right
                if (j < n - 1) {
                    val isRightO = board[i][j + 1] == O
                    if (isRightO) {
                        // point to this very node
                        union(disJointSet, i, j, i, j + 1)
                    }
                }

                // look down
                if (i < m - 1) {
                    val isDownO = board[i + 1][j] == O
                    if (isDownO) {
                        union(disJointSet, i, j, i + 1, j)
                    }
                }
            }
        }
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (board[i][j] == O) {
                    val (ii, ij) = disJointSet.parent(i, j)
                    if (!(ii == 0 || ii == m - 1 || ij == 0 || ij == n - 1)) {
                        board[i][j] = X
                    }
                }
            }
        }
    }

    private fun union(disJointSet: DisJointSet, m1: Int, n1: Int, m2: Int, n2: Int) {
        val (m1Parent, n1Parent) = disJointSet.parent(m1, n1)
        if (m1Parent == 0 || m1Parent == disJointSet._m - 1 || n1Parent == 0 || n1Parent == disJointSet._n - 1) {
            disJointSet.union(m1, n1, m2, n2)
        } else {
            disJointSet.union(m2, n2, m1, n1)
        }
    }
}