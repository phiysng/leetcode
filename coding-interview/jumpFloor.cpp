/// 面试题 10 扩展

class Solution
{
public:
    int jumpFloor(int number)
    {
        vector<int> res{1, 1, 2};
        res.resize(number + 1);
        for (size_t i = 3; i < number + 1; i++)
        {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[number];
    }
};