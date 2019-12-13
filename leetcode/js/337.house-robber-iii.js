/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
function TreeNode(val) {
    this.val = val;
    this.left = this.right = null;
}

/**
 * @param {TreeNode} root
 * @return {number}
 */
var rob = function (root) {
    let res = _rob(root);

    return Math.max(res.first, res.second);
};

/**
 * 
 * @param root 
 * @returns first: max_value can with root / max_value this root can get
 *          second: max_value  without root
 */
function _rob(root) {
    if (!root) {
        return { first: 0, second: 0 };
    }

    let left = _rob(root.left);
    let right = _rob(root.right);

    let _with = Math.max(root.val + left.second + right.second, left.first + right.first);
    let _without = left.first + right.first;

    return {
        first: Math.max(_with, _without),
        second: _without
    };
}
