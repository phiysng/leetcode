/**
 * Definition for a binary tree node.
 * class TreeNode(var _value: Int) {
 *   var value: Int = _value
 *   var left: TreeNode = null
 *   var right: TreeNode = null
 * }
 */
object Solution {

  val helper: TreeNode => (Int, Int) = (root: TreeNode)
  => {
    if (root == null) (0, 0)
    else {
      val (l: Int, ll: Int) = helper(root.left)
      val (r: Int, rr: Int) = helper(root.right)

      (root.value + ll + rr, math.max(l, ll) + math.max(r, rr))
    }
  }

  def rob(root: TreeNode): Int = {


    val (l, r) = helper(root)

    Math.max(l, r)
  }
}
