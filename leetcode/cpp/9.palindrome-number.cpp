class Solution {
public:
    bool isPalindrome(int x) {
        // 注意 10这种形式的10的倍数 下面的算法对这种数字无效
        if( x < 0 || (x > 9 && x % 10 == 0)) return false;
        if( x == 0) return true;
        
        int reversed_x = 0;
        
        while( reversed_x < x){
            reversed_x = reversed_x * 10 + x % 10;
            x /= 10;
        }
        
        return x == reversed_x || x == reversed_x / 10;
    }
};