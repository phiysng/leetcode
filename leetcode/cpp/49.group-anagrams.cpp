#include "oj_header.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        
        for(auto& s : strs){
            string s_(s);
            sort(begin(s_),end(s_));
            
            if(map.find(s_) == map.end()){
                map[s_] = { s };
            }
            else{
                map[s_].push_back(s);
            }
        }
        vector<vector<string>> res;
        for(auto &item : map){
            res.push_back(item.second);
        }
        return res;
    }
};
