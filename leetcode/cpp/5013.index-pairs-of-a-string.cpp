#include "oj_header.h"

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words)
    {
        vector<vector<int>> res;
        for (string s : words) {
            if (text.size() < s.size())
                continue;
            for (int i = 0; i < text.size() - s.size() + 1; ++i) {
                if (s == text.substr(i, s.size())) {
                    res.push_back({ i, static_cast<int>(i + s.size() - 1) });
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
