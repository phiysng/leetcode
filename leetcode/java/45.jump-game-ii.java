// O(n^2)
class Solution_v1 {
    public int jump(int[] nums) {
        int[] dis = new int[nums.length];
        Arrays.fill(dis, 0x0fffffff);

        dis[0] = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length && j < i + 1 + nums[i]; j++) {
                dis[j] = Math.min(dis[j], dis[i] + 1);
            }
        }
        return dis[dis.length - 1];
    }
}

// 可以看作上一种方法的优化
// 每次直到 end 进行一次 jump
// 相当于BFS 每层进入最远的一个入口
class Solution {
    public int jump(int[] nums) {
        int jumps = 0, end = 0, futureBegin = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            futureBegin = Math.max(futureBegin, nums[i] + i);
            if (end == i) {
                jumps++;
                end = futureBegin;
            }
        }
        return jumps;
    }
}
