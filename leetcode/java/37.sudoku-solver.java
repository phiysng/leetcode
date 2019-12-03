class Solution {
    public void solveSudoku(char[][] board) {
        backtrack(board, 0, 0);
    }

    boolean validNumber(char[][] board, int i, int j, char c) {
        // row
        for (int k = 0; k < 9; k++) {
            if (c == board[i][k]) {
                return false;
            }
        }
        // col
        for (int k = 0; k < 9; k++) {
            if (c == board[k][j]) {
                return false;
            }
        }
        // 3*3
        int row = i / 3;
        int col = j / 3;
        for (int k = row * 3; k < (row + 1) * 3; k++) {
            for (int l = col * 3; l < (col + 1) * 3; l++) {
                if (board[k][l] == c) {
                    return false;
                }
            }
        }
        return true;
    }

    boolean backtrack(char[][] board, int i, int j) {
        if (j == 9) {
            i++;
            j = 0;

            if (i == 9) {
                return true;
            }
        }
        if (board[i][j] != '.') {
            return backtrack(board, i, j + 1);
        }

        for (int k = 1; k < 10; k++) {

            if (validNumber(board, i, j, (char) ('0' + k))) {
                board[i][j] = (char) ('0' + k);
                boolean res = backtrack(board, i, j + 1);
                if (res) {
                    return true;
                } else {
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
}
