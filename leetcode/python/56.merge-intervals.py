from typing import List

# TODO: List.pop() => O(n)?

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = sorted(intervals, key=lambda x: (x[0], x[1]))
        i = 0

        while i < len(res) - 1:
            while (i < len(res) - 1):
                # cross [0,3] [2,6]
                if res[i][0] <= res[i + 1][0] <= res[i][1] <= res[i + 1][1]:
                    res[i][1] = res[i + 1][1]
                    res.pop(i + 1)
                # in [0,5] [3,4]
                elif res[i][0] <= res[i + 1][0] <= res[i + 1][0] <= res[i][1]:
                    res.pop(i + 1)
                    continue
                # no cross [0 , 1] [2,3]
                else:
                    # assert (res[i][1] < res[i + 1][0])
                    break

            i += 1

        return res
