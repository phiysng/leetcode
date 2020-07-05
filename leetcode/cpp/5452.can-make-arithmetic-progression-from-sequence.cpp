#include "oj_header.h"

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(begin(arr), end(arr));
        int dis = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++)
        {
            int _dis = arr[i] - arr[i - 1];
            if (_dis != dis)
            {
                return false;
            }
        }
        return true;
    }
};
