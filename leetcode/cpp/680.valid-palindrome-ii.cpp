#include "oj_header.h"

class Solution {
public:
    bool validPalindrome(string s)
    {
        if (is_Palindrome(s, 0, s.size() - 1))
            return true;

        int l = 0, r = s.size() - 1;

        while (l < r && s[l] == s[r]) {
            ++l;
            --r;
        }

        if (l >= r)
            return true;
        else {
            // 两头的肯定是回文串 看 i 和 j 删掉哪一个可以让中间的串保持回文
            return is_Palindrome(s, l, r - 1) || is_Palindrome(s, l + 1, r);
        }
    }

    bool is_Palindrome(string& s, int begin, int end)
    {
        while (begin < end) {
            if (s[begin] != s[end]) {
                return false;
            }
            ++begin;
            --end;
        }

        return true;
    }
};