class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {

        string s = transform(S);
        string t = transform(T);

        return s == t;
    }

    string transform(string S)
    {
        stack<int> s;
        for (char c : S)
        {
            s.push(c);
        }
        string res = "";

        while (!s.empty())
        {
            if (s.top() == '#') //退格时
            {
                s.pop();
                int times = 1;
                /// 当存在多个退格键时 注意退格键可能比剩余的字符更多
                /// 需要检测栈是否为空
                while (times)
                {

                    if (!s.empty() && s.top() == '#')
                    {
                        ++times;
                        s.pop();
                    }
                    else
                    {
                        if (s.empty())
                            break;
                        s.pop();
                        --times;
                    }
                }
            }
            else
            {
                res += s.top();
                s.pop();
            }
        }
        return res;
    }
};