#include "oj_header.h"

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0 , r = s.size() -1;
        unordered_set<char> set{'a','e','i','o','u','A','E','I','O','U'};
        while( l < r){
            while(l < r && set.find(s[l]) == set.end()){
                ++l;
            }
            
            while(l < r && set.find(s[r]) == set.end()){
                --r;
            }
            
            if(l >= r){
                break;
            }
            else{
                swap(s[l],s[r]);
                ++l;
                --r;
            }
        }
        return s;
    }
};