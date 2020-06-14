from typing import List


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        m = dict()
        for i in arr:
            if i not in m:
                m[i] = 1
            else:
                m[i] += 1
        pair = []
        for i in m:
            pair.append((i, m[i]))

        pair = sorted(pair, key=lambda x: x[1])
        idx = 0
        while(idx < len(pair)):
            if k >= pair[idx][1]:
                k -= pair[idx][1]
                idx += 1
            else:
                break

        return len(m) - idx
