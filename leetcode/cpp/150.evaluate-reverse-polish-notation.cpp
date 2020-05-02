#include "oj_header.h"

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        unordered_set<string> set{"+", "-", "*", "/"};
        stack<int> _stack;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (set.find(tokens[i]) == set.end())
            {
                _stack.push(stoi(tokens[i], nullptr));
            }
            else
            {
                int m = _stack.top();
                _stack.pop();

                int n = _stack.top();
                _stack.pop();
                _stack.push(eval(tokens[i], n, m));
            }
        }

        return _stack.top();
    }

    int eval(const string &op, int m, int n)
    {
        if (op == "+")
            return m + n;

        if (op == "-")
            return m - n;
        if (op == "*")
            return m * n;
            
        return m / n;
    }
};

