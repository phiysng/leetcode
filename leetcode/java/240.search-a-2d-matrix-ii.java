class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) return false;
        int n = matrix[0].length;
        if (n == 0) return false;

        int _m = m - 1, _n = 0;
        // 注意不要直接用三个if
        // 错误示范
        //    while (_m >= 0 && _n < n) {
        //        if (matrix[_m][_n] == target) {
        //            return true;
        //        }
        //        if (matrix[_m][_n] > target) {
        //            _m--;
        //        }
        //        if (matrix[_m][_n] < target) {
        //            _n++;
        //        }
        //
        //    }
        while (_m >= 0 && _n < n) {
            if (matrix[_m][_n] == target) {
                return true;
            } else if (matrix[_m][_n] > target) {
                _m--;
            } else if (matrix[_m][_n] < target) {
                _n++;
            }

        }
        return false;
    }

}
