use std::cmp::max;


impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.is_empty() { return 0; }

        if nums.len() == 1 {
            return nums[0];
        }

        let mut v = vec![nums[0], max(nums[0], nums[1])];

        for i in 2..nums.len() {
            let mut has_n = nums[i] + v[i - 2];
            let dont = v[i - 1];
            v.push(max(has_n, dont));
        }

        *v.last().unwrap()
    }
}