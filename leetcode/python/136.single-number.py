class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        i = 0
        for n in nums:
            i = n ^ i
        return i
