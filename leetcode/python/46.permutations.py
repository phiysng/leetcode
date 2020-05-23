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
