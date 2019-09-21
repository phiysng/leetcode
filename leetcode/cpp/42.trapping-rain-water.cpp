class Solution {
public:
    int trap(vector<int>& height)
    {
        //顺序栈、
        // 使用一个栈，每次遇到一个比栈顶元素更大的数的时候，
        // 循环以下步骤: 弹出栈顶元素，计算此时两边与弹出的栈顶元素所形成的容量
        //  直到: 1.栈顶大于(或者 大于等于)当前元素的高度
        //       2. 栈空
        // 注意判断栈是否有两个元素，当栈处于1,  而当前元素为2的时候需要break;
        stack<int> s;

        int res = 0;

        for (size_t i = 0; i < height.size(); i++) {
            // 寻找所有的小于height[curr]的点
            while (!s.empty() && height[i] > height[s.top()]) {
                int t = s.top();
                s.pop();
                if (s.empty())
                    break;

                int prev = s.top(); //左边的边界的位置
                int h = min(height[i], height[prev]); // 当前两边的最低边减去底边
                int dis = i - prev - 1;
                res += dis * (h - height[t]);
            }

            s.push(i);
        }
        return res;
    }
};