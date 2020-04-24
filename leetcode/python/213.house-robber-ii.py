from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(self._rob(nums[:-1]), self._rob(nums[1:]))

    def _rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        dp = [nums[0], max(nums[0], nums[1])]
        for i in range(2, len(nums)):
            dp.append(max(dp[i - 1], dp[i - 2] + nums[i]))
        return dp[-1]
