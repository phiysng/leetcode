class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        # 对角线和递增

        if not len(matrix) or not len(matrix[0]):
            return []

        res = []
        _reverse = False
        for i in range(len(matrix) + len(matrix[0]) - 1):
            t = []
            beg = 0 if i < len(matrix) else i - len(matrix) + 1
            while (beg <= i and beg < len(matrix[0])):
                t.append(matrix[i - beg][beg])
                beg += 1
            res += t[::-1] if _reverse else t
            _reverse = not _reverse

        return res
