class Solution:
    def numSub(self, s: str) -> int:
        l = s.split('0')
        l = [x for x in l if len(x) > 0]
        r = 0
        for sub_s in l:
            r += (1 + len(sub_s)) * len(sub_s) // 2
            r = r % (1e9 + 7)

        return int(r)
