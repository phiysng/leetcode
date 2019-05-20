/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
    /// 三指针
    nums.sort(function compare(a, b) {
        if (a < b) {           // 按某种排序标准进行比较, a 小于 b
            return -1;
        }
        if (a > b) {
            return 1;
        }
        // a must be equal to b
        return 0;
    });
    let res = []
    for (var i = 0; i < nums.length - 2; ++i) {
        if (i !== 0) {
            if (nums[i] === nums[i - 1]) continue;//重复的元素
        }
        var left = i + 1, right = nums.length - 1;
        while (left < right) {
            var sum_v = nums[i] + nums[left] + nums[right];
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
