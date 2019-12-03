import scala.collection.mutable

object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
    var begin = -1
    var res = 0
    val map = new mutable.HashMap[Char, Int]()
    for (i <- Range(0, s.length)) {
      // 已经出现且在现在的这个字串里
      if (map.contains(s(i)) && map(s(i)) > begin) {
        begin = map(s(i))
      }

      res = Math.max(res, i - begin)
      map(s(i)) = i
    }
    res

  }
}

//  0 作为下标的索引
import scala.collection.mutable

object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
    var begin = 0
    var res = 0
    val map = new mutable.HashMap[Char, Int]()
    for (i <- Range(0, s.length)) {
      if (map.contains(s(i)) && map(s(i)) >= begin) {
        begin = map(s(i)) + 1
      }

      res = Math.max(res, i - begin + 1)
      map(s(i)) = i
    }
    res

  }
}
