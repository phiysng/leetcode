class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        '''
        回溯
        '''
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
