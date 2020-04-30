from typing import List


class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        if not len(nums) or not len(nums[0]):
            return []
        m = []
        for i, row in enumerate(nums):
            for j, v in enumerate(row):
                if i + j >= len(m):
                    m.append([])
                m[i + j].append(v)
        res = [v for d in m for v in reversed(d)]
        return res
