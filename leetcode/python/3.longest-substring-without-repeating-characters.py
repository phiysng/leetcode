class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 滑动窗口
        # 记录每一个字符最近出现的次数
        # 小于起始的start继续 否则终止
        # 同时更新最近出现的索引
        # see 剑指Offer
        d = {}
        start = 0
        ans = 0
        for i , c in enumerate(s):
            if c in d:
                """
                在start前面的话保持不变
                否则这个字符及其之前肯定是有重复的字符的
                从下一个字符开始继续寻找
                """
                start = max(start,d[c]+1)
            d[c] = i #更新
            ans = max(ans,i-start+1)

        return ans
