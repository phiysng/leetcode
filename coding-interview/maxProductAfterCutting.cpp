/// 14 剪绳子

/// 可证 3*(m-3) >= 2*(n-2) > n 当 n >= 5

class Solution
{
public:
    int maxProductAfterCutting(int length)
    {
        if (length < 2)
            return 0;
        if (length == 2)
            return 1;
        if (length == 3)
            return 2;
        // 尽可能的剪长度为三的长度
        int time_of_3 = length / 3;

        //但是如果剩下的长度为4 保留
        // ∵ 3*1 < 2*2 == 4
        if (length - time_of_3 * 3 == 1)
            --time_of_3;
        /// 剪完长为3的段后尽可能的🗡长为2的段
        int time_of_2 = (length - time_of_3 * 3) / 2;
        return (int)((int)pow(3, time_of_3) * (int)pow(2, time_of_2));
    }
};
