from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """

        def can_place(row, col, s: str) -> bool:
            r = row // 3
            c = col // 3
            for i in range(len(board)):
                if board[row][i] == s:
                    return False
                if board[i][col] == s:
                    return False
            for i in range(3):
                for j in range(3):
                    if board[r * 3 + i][c * 3 + j] == s:
                        return False
            return True

        def back_track(row, col):

            if col == 9:
                row += 1
                col = 0
            if row == 9:
                return True
            if board[row][col] != '.':
                return back_track(row, col + 1)

            for i in range(1, 10):
                if can_place(row, col, str(i)):
                    board[row][col] = str(i)

                    if back_track(row, col + 1):
                        return True
                    board[row][col] = '.'

            return False

        back_track(0, 0)
