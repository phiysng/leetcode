class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}

        for index , val in enumerate(nums):
            rest = target - val
            if rest in map:
                return [index,map[rest]]
            else:
                map[val] = index
