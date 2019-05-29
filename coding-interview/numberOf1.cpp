///面试题 15 二进制中1的个数

class Solution {
public:
    int NumberOf1(int n)
    {
        int count = 0;
        unsigned int flag = 1; //只有最低位位1
        while (flag) { //循环直到1被移除
            if (n & flag)
                ++count;
            flag <<= 1;
        }
        return count;
    }
    int NumberOf1_v2(int n)
    {
        int count = 0;
        while (n) {
            ++count; //数字n还有位为1
            n = n & (n - 1);
            /// n-1会将最右面的1变为0，接着到最低位全为一
            /// 这条语句清楚了n最左边的零
        }
        return count;
    }
};
