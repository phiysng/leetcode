from typing import List

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[nums[i] - 1] != nums[i]:
                # nums[i] , nums[nums[i] - 1] = nums[nums[i] - 1] , nums[i]
                """
                TODO: python的swap语法糖不能这样用 swap的idx依赖list的值,而list的值在交换的过程中是不确定的
                see https://stackoverflow.com/questions/14836228/is-there-a-standardized-method-to-swap-two-variables-in-python/14836456#14836456
                """
                self.swap(nums, i, nums[i] - 1)

        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1

        return len(nums) + 1

    def swap(self, nums: List[int], l: int, r: int) -> None:
        nums[l], nums[r] = nums[r], nums[l]
