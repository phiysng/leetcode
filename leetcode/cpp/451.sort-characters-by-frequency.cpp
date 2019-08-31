class Solution {
public:
    string frequencySort(string s) {
        vector<string> bucket(s.size() + 1,"");
        
        unordered_map<char,int> map;
        for(char c : s){
            map[c]++;
        }
        
        for(auto& i: map){
            char c = i.first;
            int freq = i.second;
            bucket[freq].append(freq,c);
        }
        
        string res;
        for(auto it = rbegin(bucket);it < rend(bucket);++it){
            if((*it).size() > 0){
                res += *it;
            }
        }
        return res;
    }
};
