from typing import List


class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        # 矩阵对角线 row + col == const([0,(m-1)+(n-1)])

        if not len(matrix) or not len(matrix[0]):
            return []

        if not len(matrix) or not len(matrix[0]):
            return []
        m = []
        for i, row in enumerate(matrix):
            for j, v in enumerate(row):
                if i + j >= len(m):
                    m.append([])
                m[i + j].append(v)

        for i in range(len(m)):
            if i % 2 == 0:
                m[i] = m[i][::-1]
        res = [v for d in m for v in d]
        return res
