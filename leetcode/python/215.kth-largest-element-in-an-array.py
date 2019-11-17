import heapq


class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        arr = []
        for n in nums:
            heapq.heappush(arr, n)
            if len(arr) > k:
                heapq.heappop(arr)

        return arr[0]
