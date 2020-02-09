#include "oj_header.h"

class Solution
{
public:
    string addBinary(string a, string b)
    {
        int carry = 0;

        int _len = max(a.size(), b.size());

        string _a = a;
        reverse(begin(_a), end(_a));

        string _b = b;
        reverse(begin(_b), end(_b));
        string res;
        for (size_t i = 0; i < _len; i++)
        {

            int _cnt = 0;
            if (i <= _a.size() && _a[i] == '1')
            {
                ++_cnt;
            }
            if (i <= _b.size() && _b[i] == '1')
            {
                ++_cnt;
            }
            if (carry)
            {
                ++_cnt;
                carry = 0;
            }
            if (_cnt >= 2)
            {
                carry = 1;
                _cnt = _cnt % 2;
            }

            res += to_string(_cnt);
        }
        if (carry)
        {
            res += to_string(1);
        }
        reverse(begin(res), end(res));
        return res;
    }
};
