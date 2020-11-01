#include"oj_header.h"

class Solution {
public:
    int maxDepth(string s) {
        int m = 0;
        int sum = 0;
        for(auto c : s){
            if(c == '(' || c == ')'){
                sum += (c == '(' ? 1 : -1);
                if(c == '('){
                    m = max(sum,m);
                }
            }
        }

        return m;
    }
};
