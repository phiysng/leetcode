class Solution {
    // TODO: 动态规划解法
    fun countBits(n: Int): IntArray {
        val array = IntArray(n + 1)
        for (i in 1..n){
            array[i] = Integer.bitCount(i)
        }
        return array
    }
}