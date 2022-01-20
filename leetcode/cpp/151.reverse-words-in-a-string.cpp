#include "oj_header.h"

class Solution {
public:
    string reverseWords(string s)
    {
        string t = "";
        string res = t;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (t.length() == 0)
                    continue;
                if (res.length() == 0) {
                    res = t;
                } else {
                    res = t + ' ' + res;
                }
                t = "";

            } else {
                t += s[i];
            }
        }
        if (t.length()) {
            if (res.length() == 0) {
                res = t;
            } else {
                res = t + " " + res;
            }
        }
        return res;
    }
};
