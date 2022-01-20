#include "oj_header.h"

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> map;
        for (int i : arr)
        {
            map[i]++;
        }
        unordered_set<int> set;
        for (auto &p : map)
        {
            if (set.find(p.second) == set.end())
            {
                set.insert(p.second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
