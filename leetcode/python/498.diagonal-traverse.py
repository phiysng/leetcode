from typing import List


class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        # 对角线row+col和递增

        if not len(matrix) or not len(matrix[0]):
            return []
        l = []
        for i in range(len(matrix) + len(matrix[0])-1):
            t = []
            beg = 0 if i < len(matrix) else i - len(matrix) + 1
            while(beg <= i and beg < len(matrix[0])):
                t.append(matrix[i-beg][beg])
                beg += 1
            l.append(t)

        _reverse = False
        res = []

        for _l in l:
            if _reverse:
                res += _l[::-1]
            else:
                res += _l
            _reverse = not _reverse

        return res
