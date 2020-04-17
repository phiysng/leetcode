#include "oj_header.h"

/// use KMP build function.
class Solution {
public:
    string longestPrefix(string s) {
        if(s.size() <= 1) return "";

        vector<int> res{0,0};
        int j = 0;
        for(int i = 1; i < s.size();++i){
            while(j > 0 && s[i] != s[j]){
                j = res[j];
            }

            if(s[i] == s[j]){
                ++j;
            }
            res.push_back(j);
        }

        return s.substr(0,res.back());
    }
};
