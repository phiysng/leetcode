#include "oj_header.h"

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));

        int _len = max(num1.size(), num2.size());

        string res;

        for (size_t i = 0; i < _len; i++)
        {
            int n = 0;
            if (i < num1.size())
            {
                n += num1[i] - '0';
            }

            if (i < num2.size())
            {
                n += num2[i] - '0';
            }
            if (carry)
            {
                n++;
                carry = 0;
            }

            if (n >= 10)
            {
                carry = 1;
                n = n % 10;
            }

            res += to_string(n);
        }

        if (carry)
        {
            res += "1";
        }

        reverse(begin(res), end(res));

        return res;
    }
};
