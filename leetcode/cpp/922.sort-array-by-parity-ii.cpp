#include "oj_header.h"

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // WARNING: 注意位运算符的优先级
        int line = 0;
        for(int i = 0; i < A.size();i++){
            // 奇数索引上的偶数
            if((i & 0x1) == 1 && (A[i] & 0x1) == 0){

                while(line < A.size() && (A[line] & 0x1) == 0) 
                {
                    line += 2;
                }
                
                if(line < A.size()){   
                    swap(A[line],A[i]);
                }
            }
            
        }
        return A;
    }
};
