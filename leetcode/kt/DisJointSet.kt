class DisJointSet(m: Int, n: Int) {
    val matrix: IntArray
    val _m: Int
    val _n: Int

    init {
        matrix = IntArray(m * n) { -1 }
        this._m = m;
        this._n = n;
    }

    fun addRoot(m: Int, n: Int) {
        matrix[m * _n + n] = m * _n + n
    }

    fun isRoot(m: Int, n: Int): Boolean {
        return matrix[m * _n + n] == (m * _n + n)
    }

    private fun _parent(m: Int, n: Int): Int {
        var index = m * _n + n
        var parentIndex = matrix[index]
        while (parentIndex != index) {
            index = parentIndex
            parentIndex = matrix[parentIndex]
        }
        // 路径压缩
        val current = m * _n + n
        matrix[current] = index
        return index
    }

    public fun parent(m: Int, n: Int): Pair<Int, Int> {
        var index = _parent(m, n)
        return Pair(index / _n, index % _n)
    }

    /**
     * 将两个节点对应的集合合并
     */
    fun union(m1: Int, n1: Int, m2: Int, n2: Int) {
        val m1Parent = _parent(m1, n1)
        val m2Parent = _parent(m2, n2)
        if (m1Parent != m2Parent) {
            matrix[m2Parent] = m1Parent
        }
    }

    fun count(): Int {
        var count = 0
        for (i in 0 until _m) {
            for (j in 0 until _n) if (isRoot(i, j)) {
                count++
            }
        }
        return count
    }
}