// 快速幂运算
class Solution {
    public double myPow(double x, int n) {
        boolean isNeg = n < 0;
        if (n == 0)
            return 1;

        long m = Math.abs(n);

        double res = pow(x, m);

        if (isNeg) {
            return 1d / res;
        }
        return res;

    }

    private double pow(double base, long n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return base;

        long half = n / 2;
        double part = pow(base, half);
        part *= part;
        if ((n & 1) == 1) {
            part *= base;
        }

        return part;
    }
}
