import scala.collection.mutable.ListBuffer

object Solution {
  def threeSum(nums: Array[Int]): List[List[Int]] = {
    val arr: Array[Int] = nums.sorted
    val res = ListBuffer[List[Int]]()
    for (i <- arr.indices) {
      if (!(i > 0 && arr(i) == arr(i - 1))) {
        var l = i + 1
        var r = arr.length - 1
        val n = arr(i)

        while (l < r) {
          val sum_ = arr(l) + arr(r)
          if (sum_ + n == 0) {
            res.append(List[Int](arr(i), arr(l), arr(r)))
            l += 1

            while (l < arr.length && arr(l) == arr(l - 1))
              l += 1
            r -= 1
            while (r >= 0 && arr(r) == arr(r + 1))
              r -= 1

          } else {
            if (sum_ + n > 0) {
              r -= 1
            }
            else {
              l += 1
            }
          }
        }
      }
    }

    res.toList
  }
}