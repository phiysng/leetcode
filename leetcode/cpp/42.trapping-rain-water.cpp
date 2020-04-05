#include "oj_header.h"

/// refactor version.
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() <= 1)
            return 0;

        vector<int> se_stack{0}; // sequence queue.

        int res = 0;

        /// stack shall at least have one element.
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] <= height[se_stack.back()])
            {
                se_stack.push_back(i);
            }
            else
            {
                int _size = se_stack.size();
                for (int k = _size - 2; k >= 0; --k)
                {
                    int dis = i - se_stack[k] - 1;
                    int space = dis * (min<int>(height[se_stack[k]], height[i]) - height[se_stack[k + 1]]);
                    res += space;

                    se_stack.pop_back();
                    if (height[se_stack.back()] > height[i])
                    {
                        break;
                    }
                }
                /// under specific condition the loop will break
                /// - the size of se_stack is less than 2.
                /// - the height of se_stack.back() >= height[i]
                ///     - in which time the size of se_stack can be 1 also.
                if (height[se_stack.back()] >= height[i])
                {
                    se_stack.push_back(i);
                    continue;
                }
                else
                {
                    /// the se_stack must either have one item greater than height[i]
                    /// or have all item less than height[i] , in which case the size
                    /// of se_stack is 1.
                    /// assert(se_stack.size() == 1);
                    /// replace the last one.
                    /// FIMXE: when use `se_stack.back()` instead , the speed is dramatically slow
                    se_stack.pop_back();
                    se_stack.push_back(i);
                }
            }
        }
        return res;
    }
};

/// borrowed from leetcode.
class Solution
{
public:
    int trap(vector<int> &height)
    {
        //顺序栈、
        // 使用一个栈，每次遇到一个比栈顶元素更大的数的时候，
        // 循环以下步骤: 弹出栈顶元素，计算此时两边与弹出的栈顶元素所形成的容量
        //  直到: 1.栈顶大于(或者 大于等于)当前元素的高度
        //       2. 栈空
        // 注意判断栈是否有两个元素，当栈处于1,  而当前元素为2的时候需要break;
        stack<int> s;

        int res = 0;

        for (size_t i = 0; i < height.size(); i++)
        {
            // 寻找所有的小于height[curr]的点
            while (!s.empty() && height[i] > height[s.top()])
            {
                int t = s.top();
                s.pop();
                if (s.empty())
                    break;

                int prev = s.top();                   //左边的边界的位置
                int h = min(height[i], height[prev]); // 当前两边的最低边减去底边
                int dis = i - prev - 1;
                res += dis * (h - height[t]);
            }

            s.push(i);
        }
        return res;
    }
};
