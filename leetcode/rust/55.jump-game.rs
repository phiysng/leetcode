use std::cmp;

impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut dis = 0;
        for i in 0..nums.len(){
          if dis >= i{
            dis = cmp::max(dis,(i + nums[i] as usize));
          }
      }
      if dis >= nums.len() -1
      {
        return true;
      }
      false
    }
}