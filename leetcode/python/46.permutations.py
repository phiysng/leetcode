from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        回溯版本
        """
        def backtrace(first: int, n: int, res: List[List[int]], arr: List[int]) -> None:
            # terminate state
            if n == first:
                res.append(arr[:])

            for i in range(first, n):
                arr[first], arr[i] = arr[i], arr[first]  # swap
                backtrace(first + 1, n, res, arr)
                arr[first], arr[i] = arr[i], arr[first]  # swap

        res = []
        backtrace(0, len(nums), res, nums)

        return res

    def permute(self, nums: List[int]) -> List[List[int]]:
        """
        non-recursive version
        """
        r = [nums]
        for i in range(len(nums) - 1):
            _len = len(r)
            for k in range(_len):
                for j in range(i + 1, len(nums)):
                    t = r[k][:]
                    t[i], t[j] = t[j], t[i]
                    r.append(t)

        return r


class Solution_v2:
    """
    Another version of backtrace solution
    """

    def __init__(self):
        self.map = {}

    def permute(self, nums: List[int]) -> List[List[int]]:
        for i in nums:
            self.map[i] = 0

        def back_trace(t: List[int], _len: int, res: List[List[int]]):
            if _len == len(nums):
                res.append(t[:])
                return

            for key in self.map:
                if self.map[key] == 0:
                    self.map[key] = 1
                    t.append(key)
                    back_trace(t, _len + 1, res)
                    self.map[key] = 0
                    t.pop()

        r = []
        back_trace([], 0, r)
        return r
