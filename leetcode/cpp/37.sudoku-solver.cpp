#include "oj_header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        solveSudoku(board, 0, 0);
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j == 9)
            return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.')
            return solveSudoku(board, i, j + 1); //数字已经给出

        for (char c = '1'; c <= '9'; ++i) {
            if (check(board, i, j, c)) {
                //当前有效
                board[i][j] = c;
                if (solveSudoku(board, i, j + 1))
                    return true;
                else
                    // 回溯
                    board[i][j] = '.';
            }
        }
        return false;
    }

    static bool check(vector<vector<char>>& board, int i, int j, char val)
    {
        int row = i - i % 3, column = j - j % 3;
        for (int k = 0; k < 9; ++k) {
            if (board[k][j] == val)
                return false;
        }
        for (int k = 0; k < 9; ++k) {
            if (board[i][k] == val)
                return false;
        }
        for (int l = 0; l < 3; ++l) {
            for (int k = 0; k < 3; ++k) {
                if (board[row + l][column + k] == val)
                    return false;
            }
        }
        return true;
    }
};