import java.util.LinkedList;

class Solution {
    public int trap(int[] height) {
        int res = 0;
        LinkedList<Integer> stack = new LinkedList<Integer>();
        // what in stack should be something like: 7 5 3 2 1 downstairs

        for (int i = 0; i < height.length; i++) {
            if (stack.isEmpty()) {
                stack.push(i);
            } else {
                if (height[i] <= height[stack.getFirst()]) {
                    stack.push(i);
                } else {
                    while (!stack.isEmpty() && height[i] > height[stack.getFirst()]) {
                        int k = stack.getFirst();
                        stack.pop();
                        if (stack.isEmpty()) {
                            break;
                        }
                        int left_edge = stack.getFirst();
                        res += (i - left_edge - 1) * (Math.min(height[i], height[left_edge]) - height[k]);
                    }
                    stack.push(i);
                }
            }
        }
        return res;
    }
}
