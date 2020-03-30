#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题05. 替换空格

class Solution
{
public:
    string replaceSpace(string s)
    {
        int spaces = 0;

        for_each(begin(s), end(s), [&](char c) { if (c == ' ') ++spaces; });

        int _n = s.size() + spaces * 2;
        string _s(_n, '0');

        int _idx = _n - 1;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
            {
                _s[_idx--] = '0';
                _s[_idx--] = '2';
                _s[_idx--] = '%';
            }
            else
            {
                _s[_idx--] = s[i];
            }
        }

        return _s;
    }
};
