/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function (matrix, target) {
    let m = matrix.length;
    if (m == 0) return false;
    let n = matrix[0].length;
    if (n == 0) return false;

    // m line number
    // n number of elements every line has
    let i = 0;
    let j = m * n;
    while (i < j) {
        let mid = Math.floor((i + j) / 2);
        let value = matrix[Math.floor(mid / n)][mid % n];
        if (value == target) {
            return true;
        }

        if (value > target) {
            j = mid;
        }
        else {
            i = mid + 1;
        }
    }
    return false;
};
