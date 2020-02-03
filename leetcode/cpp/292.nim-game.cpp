/**
 * 我居然愚蠢的在用DP写 => TLE
 * dp[n] = !dp[i-1] || !dp[i-2] || !dp[i-3]
 * example: 0 - 21
 *  [0, 1, 1, 1, 0, 1, 
 *      1, 1, 0, 1, 1, 
 *      1, 0, 1, 1, 1, 
 *      0, 1, 1, 1, 0, 
 *      1]
 *  so we can simplify it to n % 4 != 0.
 */
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};
