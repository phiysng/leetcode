impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = vec![];
        
        for ch in s.chars().into_iter(){
            match stack.last(){
                None=>{},
                Some(&last) =>{
                    if Solution::pair(last, ch){
                        stack.pop();
                        continue;
                    }
                    
                }
            }
            stack.push(ch);
        }
        stack.is_empty()
    }

     #[inline(always)]
    fn pair(lhs :char , rhs :char )->bool{
         (lhs == '{' && rhs == '}') ||
            (lhs == '(' && rhs == ')') ||
            (lhs == '[' && rhs == ']')
    }
}
