use std::collections::HashMap;
use std::vec::Vec;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();

        let mut res = vec![];
        
        for (i,n) in nums.iter().enumerate(){
            if let Some(&idx) = map.get(&(target-n)){
                res.extend(vec![idx as i32,i as i32]);
                break;
            }
            else{
                map.insert(n,i);
            }
        }
        res

    }
}
