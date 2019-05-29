class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<int, int> map_s, map_t;
        for (char c : s)
            map_s[c]++;
        for (char c : t)
            map_t[c]++;
        return map_s == map_t;
    }
};