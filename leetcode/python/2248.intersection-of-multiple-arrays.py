class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        map = dict()
        for in_list in nums:
            for n in in_list:
                if n not in map:
                    map[n] = 1
                else:
                    map[n] += 1
        
        r = [] # final value
        num_len = len(nums)
        for k in map:
            if map[k] == num_len:
                r.append(k)
        r.sort()
        return r

# 使用集合运算 速度差不多
class Solution_v2:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        s = set(nums[0])
        for num in nums[1:]:
            s &= set(num)

        return sorted(list(s))