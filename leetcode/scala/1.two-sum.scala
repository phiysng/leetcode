// O(n^2) time 
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

// O(n) time && space
object Solution_v2 {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    val map = scala.collection.mutable.HashMap[Int, Int]()

    for (i <- 0 until nums.length) {
      if (map.contains(target - nums(i))) {
        return Array(map(target - nums(i)), i)
      }
        map.put(nums(i),i)
    }
    return Array(0, 0)

  }
}