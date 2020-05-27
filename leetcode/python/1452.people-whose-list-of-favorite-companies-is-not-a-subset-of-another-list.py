from typing import List


class Solution:
    def peopleIndexes(self, favoriteCompanies) -> List[int]:
        """
        优化: 将字符串映射为int
        优化: 根据列表长度排序 子集的长度一定小于 /不是很有效
        优化: 
        """
        m = []
        r = []
        d = {}
        for i in favoriteCompanies:
            for e in i:
                if e not in d:
                    d[e] = len(d)

        _favoriteCompanies = [{d[c] for c in x} for x in favoriteCompanies]

        for i in range(len(_favoriteCompanies)):
            m.append(set(_favoriteCompanies[i]))

        for i in range(len(_favoriteCompanies)):

            for k in range(len(favoriteCompanies)):
                if i == k:
                    continue
                if len(m[i]) > len(m[k]):
                    continue
                if m[i].issubset(m[k]):
                    break
            else:
                r.append(i)
        return r
