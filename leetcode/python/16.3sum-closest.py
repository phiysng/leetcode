class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = nums[0] + nums[1] + nums[2]

        for i in range(len(nums)-2):
            l = i + 1
            r = len(nums) - 1
            while l < r:
                t = nums[i] + nums[l] + nums[r]

                if abs(target - t) < abs(target - res):
                    res = t
                if target == t:
                    return res
                if t > target:
                    r -= 1

                else:
                    l += 1
        return res
