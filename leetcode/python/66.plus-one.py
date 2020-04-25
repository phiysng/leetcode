from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        res = digits[::-1]
        carry = 1
        for i in range(len(res)):
            res[i] += carry
            carry = res[i] // 10
            res[i] = res[i] % 10

        if carry:
            res.append(1)
        return res[::-1]
