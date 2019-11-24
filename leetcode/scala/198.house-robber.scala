object Solution {
  def rob(nums: Array[Int]): Int = {
    if (nums.length == 0) {
      return 0
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