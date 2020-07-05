from typing import List

class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        _lmin = None
        if right:
            _lmin = min(right)
        
        _rmax = None
        if left:
            _rmax = max(left)
        print(_lmin,_rmax)
        if(not right):
            return _rmax
        if(not left):
            return n-_lmin
        
        return max(n-_lmin,_rmax)
