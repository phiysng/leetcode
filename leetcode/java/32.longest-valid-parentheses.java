import java.util.Stack;

/**
 * ()())
 * -1
 * -1 0
 * -1  max = 2
 * -1 2
 * -1 max = 4
 * empty -> 3 //新的字串
 *
 */
class Solution {
    public int longestValidParentheses(String s) {

        Stack<Integer> stack = new Stack<Integer>();

        stack.push(-1);

        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                // stack可以在保证永不为空
                // 在前面push -1
                // 然后下面的 pop()让其变为空后会push当前的i
                // 从而开始一个新的字串
                stack.pop();
                // 栈空表示此时这个字串已经不是有效的子串了
                // 将此时的 i push作为新的字串的开始的标记
                // 类似于最长无重复子串的开始index
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    //当前能够获得的最长的长度
                    res = Math.max(res, i - stack.peek());
                }
            }
        }
        return res;

    }
}
