class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        int prev = 0;
        int curr = 1;
        for(int i = 2; i < N + 1; ++i){
            int t = prev + curr;
            prev = curr;
            curr = t;
        }
        return curr;
    }
};
