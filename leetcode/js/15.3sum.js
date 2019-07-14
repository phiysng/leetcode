/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    /// 三指针
    nums.sort((a, b) => a - b);
    let res = []
    for (let i = 0; i < nums.length - 2; ++i) {
        if (i !== 0) {
            if (nums[i] === nums[i - 1]) continue;//重复的元素
        }
        let left = i + 1, right = nums.length - 1;
        while (left < right) {
            let sum_v = nums[i] + nums[left] + nums[right];
            if (sum_v === 0) {
                res.push([nums[i], nums[left], nums[right]]);
                ++left;
                while (left < right && nums[left] === nums[left - 1])++left;//跳过重复的元素
                --right;
                while (right > left && nums[right] === nums[right + 1])--right; //跳过重复的元素

            }
            else {
                if (sum_v < 0) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
    }
    return res;
};
