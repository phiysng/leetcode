from typing import List

# note expression like (13 / -130) need to be floor
# python的整除与C/C++的整除规则并不相同
# C++    1 /  11 == 0 | 1 / -11  == 0
# Python 1 // 11 == 0 | 1 // -11 == -1
# 可见Python的整除是一致的向下取整 而C++则是对正负数的取整方向不同
# Python的 `int()` 函数却又和C++的规则相同了
# 换一种说法 // 调用了floor()
# 而int()则是截断整数部分 忽略小数部分
# \ref https://stackoverflow.com/questions/31036098/what-is-the-difference-between-int-and-floor-in-python-3


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        op = {'+', '-', '*', '/'}
        for i, v in enumerate(tokens):
            if v in op:
                n = stack[-1]
                stack.pop()
                m = stack[-1]
                stack.pop()

                def evalVal(op, m, n):
                    if op == '+':
                        return m + n
                    elif op == '-':
                        return m - n
                    elif op == '*':
                        return m * n
                    else:
                        return int(m / n)
                stack.append(evalVal(v, m, n))
            else:
                stack.append(int(v))
        return stack[0]
