#include "oj_header.h"

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int max_len = 0;
        for(int i : nums){
            if(i == 1){
                ++len;
                max_len = max(max_len,len);
            }
            else{
                len = 0;
            }
        }
        return max_len;
    }
};
