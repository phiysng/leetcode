class Solution {
    public int maxSubArray(int[] nums) {
        if (nums.length == 1) return nums[0];
        int n = 0;
        int res = nums[0];
        for (int i = 0; i < nums.length; i++) {
            n += nums[i];
            res = Math.max(res, n);
            if (n < 0) {
                n = 0;
            }

        }
        return res;
    }
}
