from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return
        left = 0
        right = len(nums) - 1
        for i in range(len(nums)):
            # left == right 时 [0:left-1] 为 0  [right+1:] 为 2
            # 此时 [0 , 1 , 2]都可以 可以直接退出循环了
            # left <= i <= right
            # left <= i 是总是满足的
            while nums[i] != 1 and left <= right and i <= right:
                if nums[i] == 0:
                    # [left,i-1]只可能是 1
                    nums[i], nums[left] = nums[left], nums[i]
                    left += 1
                    break
                else:
                    # right 所在可能为 0 1 22
                    nums[i], nums[right] = nums[right], nums[i]
                    right -= 1
                if left >= right or i > right:
                    break
            if i > right or left > right:
                break
