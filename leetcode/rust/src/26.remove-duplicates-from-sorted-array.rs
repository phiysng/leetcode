impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut index  = 0;
        
        if nums.len() == 0{
            return 0i32;
        }
        
        for i in 1..(nums.len()){
            if nums[i] == nums[i-1]{
                // do nothing
            }
            else{
                index +=1;
                nums[index] = nums[i];
            }
        }
        (index + 1) as i32
    }
}
