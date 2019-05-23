/// 面试题10 斐波那契数列

class Solution
{
public:
    /// O**0没有意义 返回 0/1都可以
    /// 注意处理 base == 0 && exponent <= 0 的情况
    /// 使用快速幂运算加速
    bool invalid_value = false;
    double Power(double base, int exponent)
    {
        invalid_value = false;
        if (base == 0.0 && exponent < 0)
        {
            ///对0取倒数会出错
            invalid_value = true;
            return 0.0;
        }
        /// 书上使用unsinged int来存储
        /// 这样可以避免负整数转为正整数时的溢出
        unsigned int abs_exponent = (unsigned int)exponent;
        if (exponent < 0)
            abs_exponent = (unsigned int)(-exponent);
        double result = PowerWithUnsignedExponent(base, abs_exponent);

        return exponent < 0 ? 1.0 / result : result;
    }
    double PowerWithUnsignedExponent(double base, unsigned int exponent)
    {
        /// 快速幂运算
        /// a**b = a**(b/2) * a**(b/2) b位偶数
        /// a**b = a**(b/2) * a**(b/2) *a b位奇数
        if (exponent == 0)
            return 1;
        if (exponent == 1)
            return base;

        double result = PowerWithUnsignedExponent(base, exponent / 2);
        result *= result;
        if (exponent & 0x1)
        {
            result *= base;
        }
        return result;
    }
};
