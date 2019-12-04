class Solution {
    // faltten 2 dem array
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) return false;
        int n = matrix[0].length;
        if (n == 0) return false;

        int l = 0;
        int r = m * n;

        while (l < r) {
            int mid = (l + r) / 2;
            int _m = mid / n, _n = mid % n;
            if (matrix[_m][_n] == target) {
                return true;
            }
            if (matrix[_m][_n] > target) {
                r = mid;
            }
            if (matrix[_m][_n] < target) {
                l = mid + 1;
            }
        }
        return false;

    }
}
