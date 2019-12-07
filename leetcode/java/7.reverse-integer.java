class Solution {
    public int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int p = x % 10;
            x /= 10;
            if (res > 0 && (res > Integer.MAX_VALUE / 10 || res == Integer.MAX_VALUE / 10 && p > 7))
                return 0;
            if (res < 0 && (res < Integer.MIN_VALUE / 10 || res == Integer.MIN_VALUE / 10 && p < -8))
                return 0;

            res = res * 10 + p;

        }
        return res;
    }
}
