import kotlin.math.max

class Solution_v1 {
    fun rob(nums: IntArray): Int {
        if(nums.isEmpty())
            return 0
        if(nums.size == 1)
            return nums[0]

        val arr = IntArray(nums.size);
        arr[0] = nums[0]
        arr[1] = max(nums[0],nums[1])
        for(i in 2 until nums.size){
            arr[i] = max(nums[i] + arr[i-2],arr[i-1])
        }
        return arr.last()
    }
}

class Solution_v2 {
    fun rob(nums: IntArray): Int {
        if (nums.isEmpty())
            return 0
        if (nums.size == 1)
            return nums[0]

        var preOpt = nums[0]
        var curOpt = max(nums[0], nums[1])
        for (i in 2 until nums.size) {
            val nextOpt = max(nums[i] + preOpt, curOpt)
            preOpt = curOpt;
            curOpt = nextOpt;
        }
        return curOpt
    }
}