impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n == 1{
             return 1;
        }
        if n == 2{
             return 2;
        }

        let mut prev = 1;
        let mut curr = 2;

        for i in 3..(n+1){
            curr += prev;
            prev = curr - prev;
            
        }
        curr
    }
}
