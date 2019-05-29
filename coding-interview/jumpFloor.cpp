/// 面试题 10 扩展
/// 青蛙跳台阶 的可能性

/// 扩展 2 * X 的箱子可以由多少种 2 * 1的箱子组成

class Solution {
public:
    int jumpFloor(int number)
    {
        vector<int> res{ 1, 1, 2 };
        res.resize(number + 1);
        for (size_t i = 3; i < number + 1; i++) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[number];
    }
};