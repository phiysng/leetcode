impl Solution {
    pub fn reverse(x: i32) -> i32 {
       let mut y  = x as i32;
        let mut res :i32 = 0;
        
        while y != 0 {
            let  dight =y %10;
            
            if res > std::i32::MAX / 10 || res == std::i32::MAX / 10 && dight > 7{
                return 0;
            }

            if res < std::i32::MIN / 10 || res == std::i32::MIN / 10 && dight < -8{
                return 0;
            }
            res = res*10 + dight;
            y /= 10;
        }
        return res;

    }
}
