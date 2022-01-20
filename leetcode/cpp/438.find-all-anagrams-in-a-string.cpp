#include "oj_header.h"

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        vector<int> map_p(26), map_s(26);
        if (s.size() < p.size())
            return {};
        for (char c : p)
            ++map_p[c - 'a'];

        for (int i = 0; i < p.size(); ++i)
        {
            ++map_s[s[i] - 'a'];
        }
        if (map_p == map_s)
            res.push_back(0);

        for (int i = p.size(); i < s.size(); ++i)
        {
            ++map_s[s[i] - 'a'];
            --map_s[s[i - p.size()] - 'a'];
            if (map_s == map_p)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

///非常慢
// class Solution
// {
// public:
//     vector<int> findAnagrams(string s, string p)
//     {
//         if (s.size() < p.size())
//             return {};
//         vector<int> res;
//         vector<int> map_t(26);
//         init(p, map_t);
//         unordered_map<string, int> cache;

//         for (int i = 0; i < s.size() - p.size() + 1; ++i)
//         {
//             string t = s.substr(i, p.size());
//             if (t == p)
//             {
//                 res.push_back(i);
//                 continue;
//             }
//             if (cache[t] != 0)
//             {
//                 res.push_back(i);
//                 continue;
//             }
//             if (isAnagram(t, map_t))
//             {
//                 res.push_back(i);
//                 cache[t] = true;
//             }
//             else
//             {
//                 cache[t] = false;
//             }
//         }
//         return res;
//     }

//     bool isAnagram(const string &s, vector<int> &map_t)
//     {
//         vector<int> map_s(26);

//         for (char c : s)
//             map_s[c - 'a']++;

//         return map_s == map_t;
//     }

//     void init(const string &t, vector<int> &map_t)
//     {
//         for (char c : t)
//             map_t[c - 'a']++;
//     }

// private:
// };