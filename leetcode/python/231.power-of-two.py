class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        def numOfOne(n: int):
            res = 0
            while n:
                res = res + 1
                n = n & (n - 1)
            return res

        if n <= 0:
            return False
        return numOfOne(n) == 1
