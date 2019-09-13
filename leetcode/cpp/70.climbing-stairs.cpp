class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int prev = 1;
        int curr = 2;
        for (int i = 3; i < n + 1; ++i) {
            curr += prev;
            prev = curr - prev;
        }
        return curr;
    }
};
