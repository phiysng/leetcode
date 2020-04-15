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

        /// \arg i index of text
        /// \arg j index of pattern
        for (int i = 0, j = 0; i < m; ++i)
        {
            /// \bug
            /// 1.如果字符相等 => break [PS:此时同样可能存在 j == 0]
            /// 2.如果字符不等 且不处于j == 0(有可回退的位置) => 回退到next[j]位置
            /// 3.字符不等且j == 0 => 没有回退的可能 break
            while (j > 0 && s[i] != p[j])
            {
                j = table[j];
            }

            /// 此时代码可能处于(1 || 3) 情况
            /// j一种情况下通过next表跳转了(0-...)次位置并且某一次s[i] == p[j]
            /// 或者一路回退到j == 0
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
        ///<summary>
        /// res[0] => 字符串第二个字符前面没有字符
        /// res[1] => 字符串第二个字符前面只有一个字符 不会有重复的[前缀/后缀]
        ///</summary>
        vector<int> res{0, 0};

        int pos = 0;
        /// \note i = 1时求出的是[0,1]范围内的最长公共前后缀
        /// 亦即 i = 2(第三个字符)不匹配时所对应的next[i]
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
