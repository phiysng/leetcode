from typing import List


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
