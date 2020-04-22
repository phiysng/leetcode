import math as m
from typing import List

class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        width = int(m.sqrt(area))
        while width > 0:
            if area % width == 0:
                return [int(area / width), width]
            else:
                width -= 1
        return [0, 0]

