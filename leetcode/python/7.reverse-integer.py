class Solution:
    def reverse(self, x: int) -> int:
        rev = 0
        y = abs(x)

        while y:
            rev = rev*10 + y % 10
            y //= 10

        sign = -1 if x < 0 else 1

        if(rev > 0x7fffffff):
            return 0

        return sign * rev
