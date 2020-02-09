#include "oj_header.h"

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.size();
        int n = num2.size();

        // 0...[1...m+n-2]...m+n-1
        // max value < 1x10^(m+n) so ans is enough to save the result.
        string ans(m + n, '0');

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                // the current value of position i + j -1 , including
                // new multiply and remains.
                int sum = (num1[i] - '0') * (num2[j] - '0') + ans[i + j + 1] - '0';
                // remainder.
                ans[i + j + 1] = sum % 10 + '0';
                // carry val.
                ans[i + j] += sum / 10;
            }
        }
        
        // substr from the first valid position(non-zero)
        for (size_t i = 0; i < m + n; i++)
        {
            if (ans[i] != '0')
            {
                return ans.substr(i);
            }
        }

        return "0";
    }
};
