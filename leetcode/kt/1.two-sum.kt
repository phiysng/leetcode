class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = TreeMap<Int, Int>()
        for (i in nums.indices) {
            if (map.containsKey(target - nums[i])) {
                println(map[target - nums[i]])
                return intArrayOf(map[target - nums[i]] ?: 0, i)
            } else {
                map[nums[i]] = i
            }
        }
        return intArrayOf(0, 0)
    }
}
