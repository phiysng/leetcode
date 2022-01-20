#include "oj_header.h"

class Solution {
public:

    int tribonacci(int n) {
        if(n == 0){
            return 0;
        }
        if(n < 3){
            return 1;
        }

        int t1 = 0;
        int t2 = 1;
        int t3 = 1;

        for(int i = 3 ; i <= n; i++){
            int v = t1 + t2 + t3;
            swap(t2 , t1); 
            swap(t3 , t2);
            t3 = v;
        }

        return t3;
    }
};