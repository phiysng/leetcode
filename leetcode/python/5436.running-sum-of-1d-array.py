from typing import List


class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        r = [nums[0]]
        for i in range(1, len(nums)):
            r.append(r[-1] + nums[i])
        return r
