class Solution {
    public int maxProduct(int[] nums) {
        int _max = (nums[0] - 1) * (nums[1] - 1);
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                var v = (nums[i] - 1) * (nums[j] - 1);
                _max = Math.max(_max, v);
            }
        }
        return _max;
    }
}