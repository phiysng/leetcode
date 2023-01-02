class Solution {
    /**
     * hand write bit count.
     */
    fun hammingDistance(x: Int, y: Int): Int {
        var value: Int = x xor y
        var count = 0
        while (value != 0) {
            if ((value and 1) > 0) {
                count++
            }
            value = value shr 1
        }
        return count
    }

    /**
     * use build in extension functions
     */
    fun hammingDistance_buildIn(x: Int, y: Int): Int {
        val value: Int = x xor y
        return value.countOneBits()
    }
}