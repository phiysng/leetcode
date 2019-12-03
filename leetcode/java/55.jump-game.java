class Solution {
    public boolean canJump(int[] nums) {
        int d = nums[0];
        for (int i = 0; i < nums.length && i <= d; i++) {
            d = Math.max(d, i + nums[i]);
        }
        return d >= nums.length - 1;
    }
}
