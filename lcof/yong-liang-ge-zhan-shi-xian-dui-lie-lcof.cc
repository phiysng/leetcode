#include "../leetcode/leetcode/cpp/oj_header.h"

/// 面试题09. 用两个栈实现队列

class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s2.empty()){
            while (!s1.empty())
            {
                int v = s1.top();
                s1.pop();
                s2.push(v);
            }
            
        }
        if(s2.empty()) return -1;
        int v = s2.top();
        s2.pop();
        return v;
    }

private:
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
