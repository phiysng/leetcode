use std::cmp::max;


impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        
        if(nums.len() == 0){ return 0;}
        
        let mut v = Vec::new();
        v.push(nums[0]);
        let m = *nums.first().unwrap();

        for i in 1..nums.len() {
            let mut has_n = nums[i];
            if i > 1{
                has_n +=   v[i - 2];
            }
            let dont = v[i - 1];
            v.push(max(has_n, dont));

        }

        *v.last().unwrap()
    }
}
