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
        while (s1.size() > 0)
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

/// 相关: 两个队列实现一个栈
/// see https://leetcode-cn.com/problems/implement-stack-using-queues/submissions/
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    queue<int> q1, q2;

    /** Push element x onto stack. */
    void push(int x)
    {
        if (!q1.empty())
        {
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        auto x = q1.front();
        q1.pop();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

/// 可以只是用一个队列实现
class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int size = q.size();
        for (int i = 0; i < q.size() - 1; ++i)
        {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        int t = q.front();
        q.pop();
        return t;
    }

    /** Get the top element. */
    int top()
    {
        int t = pop();
        push(t);
        return t;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};
