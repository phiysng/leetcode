from typing import List, Tuple

# 使用二分搜索 应该惰性的进行构建列表
# build数组的时间很长


class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        if m * k > len(bloomDay):
            return -1

        days = set(bloomDay)

        days_list = list(days)
        days_list.sort()

        l = 0
        r = len(days_list)

        while l < r:
            mid = (l + r) // 2
            status = []
            status_ = []
            for t in bloomDay:
                status.append(1 if t <= days_list[mid] else 0)
                if mid != 0:
                    status_.append(1 if t <= days_list[mid-1] else 0)

            valid_ = self.isValid(status, m, k)
            if(valid_ and (mid == 0 or not self.isValid(status_, m, k))):
                return days_list[mid]
            if valid_ is True:
                r = mid
            else:
                l = mid + 1

        return -1

    def isValid(self, view: List[int], m: int, k: int) -> bool:
        sub_ = ''.join(map(str, view)).split('0')
        cnt = sum(len(x) // k for x in sub_)
        return cnt >= m
    
    # 参考第二十一名周赛同学的答案 反而更慢了
    def isValid_(self, view: List[int], m: int, k: int) -> bool:
            n = len(view)
            view = [0] + view
            
            for i in range(len(view)):
                view[i] += view[i-1]
            cnt = 0
            i  = 1
            while( i + k -1 <= n):
                if view[i+k-1] - view[i-1] == k:
                    cnt += 1
                    i += k - 1

                i += 1
            return cnt >= m
