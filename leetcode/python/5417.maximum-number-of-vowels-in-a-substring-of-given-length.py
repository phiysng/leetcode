class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        valid = {'a', 'e', 'i', 'o', 'u'}
        v = 0
        for i in range(k):
            if s[i] in valid:
                v += 1
        t = v
        for i in range(k, len(s)):
            if v == k:
                return k
            if s[i] in valid:
                t += 1
            if s[i-k] in valid:
                t -= 1
            v = max(v, t)
        return v
