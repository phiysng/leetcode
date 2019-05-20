/**
 * @param {number[]} nums
 * @return {number[]}
 */

var majorityElement = function (nums) {
    //摩尔投票法
    var first = null, second = null;
    var first_c = 0, second_c = 0;//计数
    if (nums === null || nums.length === 0) {
        return [];
    }
    let res = [];
    for (var i = 0; i < nums.length; ++i) {
        if (first === nums[i]) {
            first_c++;
        }
        else {
            if (second === nums[i]) {
                second_c++;
            }
            else {
                if (first_c === 0) {
                    [first, first_c] = [nums[i], 1];
                }
                else {
                    if (second_c === 0) {
                        [second, second_c] = [nums[i], 1];
                    }
                    else {
                        first_c--;
                        second_c--;
                    }
                }
            }
        }
    }
    var cnt_a = 0, cnt_b = 0;
    for (var i = 0; i < nums.length; ++i) {
        if (nums[i] === first) {
            cnt_a++;
        }
        if (nums[i] === second) {
            cnt_b++;
        }
    }

    if (cnt_a > Math.floor(nums.length / 3)) res.push(first);
    if (cnt_b > Math.floor(nums.length / 3)) res.push(second);

    return res;
};