
from typing import List


class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        return self.quickSort(nums)

    def quickSort(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        v = nums[0]
        left = [n for n in nums[1:] if n < v]
        right = [n for n in nums[1:] if n >= v]

        l = self.quickSort(left)
        r = self.quickSort(right)

        return l + [nums[0]] + r
