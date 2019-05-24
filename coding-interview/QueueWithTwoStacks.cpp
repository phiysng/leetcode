/// 9 用两个栈实现队列
// 使用模板

#include <stack>
using namespace std;

template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void push(const T &node);
    T front();

private:
    stack<T> s1, s2;
};

template <typename T>
T CQueue<T>::front()
{
    if (s2.size() == 0)
    {
        while (s1.size() >0
        {
            s2.push(s1.top());
            s1.pop();
        }
    }
    if (s2.size() == 0)
    {
        throw new exception("Queue is Empty");
    }

    T head = s2.top();
    s2.pop();
    return head;
}

template <typename T>
void CQueue<T>::push(const T &item)
{
    s1.push(item);
}

/// 简单版本
class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1; //入栈
    stack<int> stack2; //出
};
