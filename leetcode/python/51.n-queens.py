from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def could_place(row, col):
            # 主对角线(hill) row + col = const(y=m-x(k>0))
            # 次对角线(hill) row + col = const(y=m+x(k>0))

            # cols is empty && hill not used && dale not used
            return not (cols[col] + hill_diagonals[row - col] + dale_diagonals[row + col])
        
        # FIXME: 使用了list[-1]语法
        def place_queen(row, col):
            queens.append((row, col))
            cols[col] = 1
            hill_diagonals[row - col] = 1
            dale_diagonals[row + col] = 1

        def remove_queen(row, col):
            queens.pop()
            cols[col] = 0
            hill_diagonals[row - col] = 0
            dale_diagonals[row + col] = 0

        def add_solution():
            solution = []
            for _, col in sorted(queens):
                solution.append('.' * col + 'Q' + '.' * (n - col - 1))
            output.append(solution)

        # 从第0行第0列开始搜索
        # 下一个起点:第0行第1列
        # 迭代行 寻找可能的列 如果不存在 回溯到上一行
        def backtrack(row=0):
            for col in range(n):
                if could_place(row, col):
                    place_queen(row, col)
                    # 在第(0-row)层有合法的位置
                    if row + 1 == n:
                        add_solution()
                    else:
                        backtrack(row + 1)
                    remove_queen(row, col)

        cols = [0] * n
        # 一条对角线(x+y) == const[0,2*(n-1)]
        # 一条对角线(x-y) == const[n-1,n-1]
        hill_diagonals = [0] * (2 * n - 1)
        dale_diagonals = [0] * (2 * n - 1)
        queens = []
        output = []
        backtrack()
        return output
