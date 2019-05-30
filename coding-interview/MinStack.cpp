/// 30 包含min函数的栈

#include"array_util.h"
using namespace std;

template <typename T>
class StackWithMin {
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T> m_data; // 数据栈，存放栈的所有元素
    std::stack<T> m_min; // 辅助栈，存放栈的最小元素
};

template <typename T>
void StackWithMin<T>::push(const T& value)
{
    // 把新元素添加到辅助栈
    m_data.push(value);

    // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
    // 否则把之前的最小元素重复插入辅助栈里
    if (m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T>
const T& StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

//重载函数 C++将返回值的类型也作为重载标签的一部分
template <typename T>
T& StackWithMin<T>::top() { return m_data.top(); }

template <typename T>
const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T>
bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T>
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

/// 稍微不同的实现，min 与data不等大小
/// 除非出现更小或相等的值，否则不向最小栈中添加新的值

class Solution {
public:
    void push(int value)
    {
        s1.push(value);
        if (mins.empty() || mins.top() >= value)
            mins.push(value);
    }
    void pop()
    {
        int ret = s1.top();
        s1.pop();
        if (mins.top() == ret)
            mins.pop();
    }
    int top() { return s1.top(); }
    int min() { return mins.top(); }

private:
    stack<int> s1;
    stack<int> mins; //最小栈
};
