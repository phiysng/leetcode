object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    for (i <- 0 until nums.length) {
      for (j <- (i + 1) until nums.length) {
        if (nums(i) + nums(j) == target) {
          return Array(i, j)
        }
      }
    }

    Array()
  }
}