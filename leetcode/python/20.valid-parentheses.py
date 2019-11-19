class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) == 0:
            return True
        if len(s) % 2 == 1:
            return False

        stack = []
        map = dict()
        map[')'] = '('
        map[']'] = '['
        map['}'] = '{'

        for i in s:
            if i not in map:
                stack.append(i)
            else:
                if len(stack) > 0 and stack[-1] == map[i]:
                    stack.pop()
                else:
                    return False

        return len(stack) == 0
