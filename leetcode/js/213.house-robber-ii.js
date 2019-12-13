/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    if (nums.length == 0) return 0;
    if (nums.length == 1) return nums[0];
    if (nums.length == 2) return Math.max(nums[0], nums[1]);

    return Math.max(_rob(nums.slice(0, nums.length - 1)), _rob(nums.slice(1)))
};

/**
 * @param {number[]} nums
 * @return {number}
 */
var _rob = function (nums) {
    if (nums.length == 0) return 0;
    if (nums.length == 1) return nums[0];
    if (nums.length == 2) return Math.max(nums[0], nums[1]);

    let dp = [nums[0], Math.max(nums[0], nums[1])];

    for (let i = 2; i < nums.length; i++) {
        const element = nums[i];
        dp.push(Math.max(element + dp[i - 2], dp[i - 1]));
    }

    return dp[dp.length - 1];

};