from typing import List

# valid ip address has 4 number, each of them is [0,255] and is valid decimal number
# which indicates we need to rule out number like this : [01,00]


class Solution:
    def __init__(self):
        self.validIp = []

    def restoreIpAddresses(self, s: str) -> List[str]:
        self.validIp.clear()
        self._restoreIpAddresses(s, [], 3)

        return self.validIp
    # ip is either 0 or 123 , 0 can't be the hightest bit of non-zero number

    def checkValidIpNum(self, s: str):
        return len(s) != 1 and s[0] == '0'

    def _restoreIpAddresses(self, s: str, partial: List[str], iteration: int) -> None:
        if iteration < 0:
            return
        if iteration == 0:
            if len(s) >= 4:
                return
            if self.checkValidIpNum(s):
                return
            _i = int(s)
            if 0 <= _i <= 255:
                partial.append(s)
                self.validIp.append('.'.join(partial))
                partial.pop()
            return

        for i in range(1, 4):
            if len(s[i:]) < iteration:
                return
            if len(s[i:]) > iteration * 3:
                continue
            sub_s = s[:i]
            if i != 1 and sub_s[0] == '0':
                continue
            if iteration == 3:
                partial = []

            if int(sub_s) > 255:
                continue
            partial.append(sub_s)
            # recursive to next level
            self._restoreIpAddresses(s[i:], partial, iteration - 1)
            partial.pop()  # pay attention, DFS need to pop this back
