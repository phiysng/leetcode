use std::cmp::max;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        if nums.len() == 1 {
            return nums[0];
        }


        max(Self::_rob(&nums[..nums.len() - 1]), Self::_rob(&nums[1..]))
    }

    pub fn _rob(nums: &[i32]) -> i32 {
        if nums.is_empty() {
            return 0;
        }

        if nums.len() == 1 {
            return nums[0];
        }

        let mut res: Vec<i32> = vec![nums[0], max(nums[0], nums[1])];

        for i in 2..nums.len() {
            res.push(max(nums[i] + res[i-2], res[i - 1]));
        }

        *res.last().unwrap()
    }
}
