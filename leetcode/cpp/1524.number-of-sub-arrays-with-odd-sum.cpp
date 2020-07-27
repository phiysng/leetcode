#include "oj_header.h"

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0; // 奇数和次数
        // 第一个数是奇数的时候 存在一个子数组
        int even = 1; //偶数和次数
        int64_t sum = 0;
        
        int64_t ans = 0;

        for(auto& n :arr){
            sum += n;
            if(sum % 2){
                // 当前和为偶数 则左边的子数组数组和为奇数 右边剩下的子数组(包括n)和为奇数
                ans += even;
                odd++;
            }
            else{
                // 当前和为奇数 则左边的子数组数组和为偶数时 右边剩下的子数组(包括n)和为奇数
                ans += odd;
                even++;
            }
            
        }
        return ans % (1000000000 + 7);
    }
};
