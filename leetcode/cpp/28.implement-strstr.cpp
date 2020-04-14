#include "oj_header.h"

/// strStr implement with KMP algorithm

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;

        auto res = Match(haystack, needle);

        cout << (res.size());

        return res.empty() ? -1 : res.front();
    }

    static vector<int> Match(const string &s, const string &p)
    {
        auto table = Build(p);

        vector<int> res;

        int m = s.size();
        int n = p.size();

        for (int i = 0, j = 0; i < m; ++i)
        {
            /// \bug
            while (j > 0 && s[i] != p[j])
            {
                j = table[j];
            }
            /// \bug
            if (s[i] == p[j])
            {
                ++j;
            }

            if (j == n)
            {
                res.push_back(i - n + 1);
                j = table[j];
            }
        }

        return res;
    }

    static vector<int> Build(string v)
    {
        vector<int> res{0, 0};

        int pos = 0;

        for (int i = 1; i < v.size(); ++i)
        {
            while (pos && v[i] != v[pos])
            {
                /// \bug
                pos = res[pos];
            }

            if (v[i] == v[pos])
            {
                pos++;
            }

            res.push_back(pos);
        }

        return res;
    }
};
