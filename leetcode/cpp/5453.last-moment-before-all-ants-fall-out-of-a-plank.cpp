#include "oj_header.h"

#include <optional>

/**
 * @brief 碰撞之后改变方向 可以看成比不同方向的蚂蚁直接交错过去了
 * 两者是等效的 <- 一开始的想法是进行模拟 以0.5为步长不断迭代
 * 实现过程中发现两遍增删同一个对象 相当于什么都没干
 */
class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {
        swap(left, right);
        optional<int> lmin = left.empty() ? nullopt : make_optional<int>(*std::min_element(left.begin(), left.end()));
        optional<int> rmax = right.empty() ? nullopt : make_optional<int>(*std::max_element(right.begin(), right.end()));

        if (!lmin.has_value())
        {
            return *rmax;
        }
        if (!rmax.has_value())
        {
            return n - *lmin;
        }

        return max<int>(n - *lmin, *rmax);
    }
};
