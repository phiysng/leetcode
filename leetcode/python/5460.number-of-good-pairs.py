import itertools
from typing import List

class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        m = {}
        for n in nums:
            if n not in m:
                m[n] = 1
            else:
                m[n] += 1

        r = 0
        for key in m:
            if m[key] <= 1:
                continue
            r += len(list(itertools.combinations(list(range(m[key])), 2)))
        return r
