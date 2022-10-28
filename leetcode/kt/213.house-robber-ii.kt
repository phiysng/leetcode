import kotlin.math.max

class Solution {
    fun rob(nums: IntArray): Int {
        if(nums.isEmpty())
            return 0
        if(nums.size == 1)
            return nums.last()
        if(nums.size == 2)
            return max(nums[0],nums[1])
        
        val left = doRob(nums,0,nums.size-1);
        val right = doRob(nums,1,nums.size);

        return max(left,right)
    }

    fun doRob(nums: IntArray, from: Int, to: Int): Int {
        var prev : Int = nums[from]
        var curr = max(nums[from],nums[from+1])
        for(i in from + 2 until to){
            val now = max(prev + nums[i],curr)
            prev = curr
            curr = now;
        }
        return curr
    }
}