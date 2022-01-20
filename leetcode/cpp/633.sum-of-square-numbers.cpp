#include "oj_header.h"

class Solution {
public:
    bool judgeSquareSum(int c) {

        if(c <= 2) return true;
        
        int64_t l = 0 , r = sqrt(c);
        
        while(l <= r){
            int64_t t = l*l + r*r;
            if(t == c){
                return true;
            }
            if(t > c){
                --r;
            }
            else{
                ++l;
            }
        }
        
        return false;
    }
};
