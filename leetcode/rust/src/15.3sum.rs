impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        if nums.len() < 3 {
            return vec![]
        }

        let mut nums_ = nums;
        // 升序数组
        nums_.sort();
        let mut results : Vec<Vec<i32>> = Vec::new();
        for (index, a) in    nums[0..nums_.len() - 2].iter().enumerate() {

            let a = *a;
            let mut start = index +1;
            let mut end = nums_.len()-1;
            if index != 0 && nums_[index-1] == nums_[index]{
                continue;
            }
            while start < end{
                let sum = nums_[start]+ nums_[end]+a;
                if sum ==0{
                    results.push(vec![a,nums_[start],nums_[end]]);
                    start+=1;
                    end -=1;
                    while start < end && nums_[start-1] == nums_[start]{
                        start+=1;
                    }
                     while start < end && nums_[end+1] == nums_[end]{
                        end-=1;
                    }
                }
                else{
                    if sum > 0{
                        end -=1;
                    }
                    else{
                        start+=1;
                    }
                }
            }
        }
        results
    }
}
