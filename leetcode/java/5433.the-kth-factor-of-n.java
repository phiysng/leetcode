import java.util.ArrayList;

class Solution {
    public int kthFactor(int n, int k) {
        var factors = new ArrayList<Integer>();
        var latters = new ArrayList<Integer>();
        factors.add(1);
        latters.add(n);
        int sqrt_ = (int) Math.sqrt(n);
        for (int i = 2; i < sqrt_ + 1; i++) {
            if (n % i == 0) {
                factors.add(i);
                int _i = n / i;
                if(_i != i){
                    latters.add(_i);
                }
               

            }
        }

        for (int i = latters.size() - 1; i >= 0; i--) {
            factors.add(latters.get(i));
        }
        if (factors.size() < k) return -1;
        return factors.get(k - 1);
    }
}
