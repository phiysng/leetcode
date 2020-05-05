class Solution {
    fun findDiagonalOrder(nums: List<List<Int>>): IntArray {
        if (nums.isEmpty() || nums[0].isEmpty()) return IntArray(0)
        val m = ArrayList<ArrayList<Int>>()
        for (i in nums.indices) {
            for (j in nums[i].indices) {
                if (i + j >= m.size) {
                    m.add(ArrayList())
                }

                m[i + j].add(nums[i][j])
            }
        }
        m.iterator().forEach { a ->
            a.reverse()
        }

        return m.flatten().toIntArray()

    }
}
