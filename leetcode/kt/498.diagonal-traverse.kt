class Solution {
    fun findDiagonalOrder(matrix: Array<IntArray>): IntArray {
        if (matrix.isEmpty() || matrix[0].isEmpty()) return IntArray(0)

        val m = ArrayList<ArrayList<Int>>()
        for (i in matrix.indices) {
            for (j in matrix[i].indices) {
                if (i + j >= m.size) {
                    m.add(ArrayList())
                }

                m[i + j].add(matrix[i][j])
            }
        }

        for (i in m.indices) {
            if (i % 2 == 0) {
                m[i].reverse()
            }
        }

        return m.flatten().toIntArray()
    }
}
