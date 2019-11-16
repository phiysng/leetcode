class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        m = dict()

        idx = 0
        res = 0
        for i, c in enumerate(s):
            if c in m and m[c] >= idx:
                '''
                在start前面的话保持不变
                否则这个字符及其之前肯定是有重复的字符的
                从这个重复的字符的下一个字符开始继续寻找
                '''
                res = max(res, i - idx)  # 计算当前的最大长度
                # 开始的idx更新
                idx = m[c] + 1

            m[c] = i
            res = max(res, i - idx + 1)
        return res


class Solution_v2:
    '''
    未优化的版本
    '''

    def lengthOfLongestSubstring(self, s: str) -> int:
        m = dict()

        '''
        对于每一个char c 如果没出现 continue
        出现了:
            在当前字串的索引之前:continue
            之后: map出现位置之后一位
        '''
        idx = 0
        res = 0
        for i, c in enumerate(s):
            if c not in m:
                pass
            else:
                if m[c] < idx:
                    pass

                else:
                    res = max(res, i - idx)
                    idx = m[c] + 1
            m[c] = i
            print(res, i - idx + 1)
            res = max(res, i - idx + 1)
        return res
