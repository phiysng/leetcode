class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        vector<int> flag(S.size());
        stack<char> s;
        s.push('(');
        flag[0] = 1;
        flag[flag.size() - 1] = 1;
        for (size_t i = 1; i < S.size(); i++)
        {
            if (S[i] == ')')
            {
                if (s.size() == 1) //只有一个 '('
                {
                    flag[i] = 1;
                    if (i != S.size() - 1)
                    {
                        ++i;
                        s.push('('); // 1
                        flag[i] = 1;
                    }
                }
                s.pop(); // 2  这两处其实正好抵消
            }
            else if (S[i] == '(')
                s.push('(');
        }
        string res = "";
        for (size_t i = 0; i < S.size(); i++)
        {
            if (!flag[i])
                res += S[i];
        }
        return res;
    }
};
