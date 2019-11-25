object Solution {
  def rob(nums: Array[Int]): Int = {
    // corner case
    if(nums.length == 0) return 0
    if(nums.length == 1) return nums(0)
      
    // pay attention to the slice edge.
    val first = simple_rob(nums.slice(0, nums.length - 1))
    val second = simple_rob(nums.slice(1, nums.length))
    if(first > second) return first
    second
  }

  def simple_rob(nums: Array[Int]): Int = {
    if (nums.length == 0) {
      0
    }
    if (nums.length == 1) {
      return nums(0)
    }
    if (nums.length == 2) return {
      if (nums(0) > nums(1)) nums(0)
      else nums(1)
    }
    val res = new Array[Int](nums.length)
    res(0) = nums(0)
    res(1) = if (nums(0) > nums(1)) nums(0) else nums(1)

    for (i <- Range(2, nums.length)) {
      res(i) = if (res(i - 1) > (res(i - 2) + nums(i))) {
        res(i - 1)
      }
      else {
        (res(i - 2) + nums(i))
      }
    }

    res(res.length - 1)
  }
}