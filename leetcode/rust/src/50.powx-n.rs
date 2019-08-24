impl Solution {
    // 快速幂运算
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if n == 0 {
            return 1.0;
        }

        let is_neg :bool = n < 0;

        let mut abs_n = n;
        if abs_n < 0{
            abs_n = -abs_n;
        }
        let mut res = Self::my_pow_inner(x,n);

        if is_neg {
            return 1.0f64 / res;
        }
        res

    }

    // n >= 0
    pub fn my_pow_inner(x : f64,n:i32) -> f64{
        if n == 0{
            return 1.0;
        }
        
        if n == 1{
            return x;
        }

        let mut res = Self::my_pow_inner(x,n/2);
        res *= res;

        if (n & 1) == 1{
            res *= x;
        }
        res

    }
}