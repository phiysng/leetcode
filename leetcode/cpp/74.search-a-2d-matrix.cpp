class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            int val = matrix[row][col];
            if (val == target)
                return true;
            if (val > target)
                col--;
            else
                row++;
        }
        return false;
    }
};
