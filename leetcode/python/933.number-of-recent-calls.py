import collections

class RecentCounter:

    def __init__(self):
        self.pings = collections.deque()

    def ping(self, t: int) -> int:
        self.pings.append(t)
        left_limit = (t - 3000) if (t - 3000) >= 1 else 0

        while left_limit and len(self.pings) and left_limit > self.pings[0]:
            self.pings.popleft()

        return len(self.pings)

# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
