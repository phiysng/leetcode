struct MinStack {
    stack:Vec<i32>,
    minstack:Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {

    /** initialize your data structure here. */
    fn new() -> Self {
        MinStack{
            stack: Vec::new(),
            minstack: Vec::new(),
        }
    
    }
    
    fn push(&mut self, x: i32) {
        // let x = x as i64;
        if self.stack.is_empty()       
        {        
            self.stack.push(x);
            self.minstack.push(x);
        }
        else{
            self.stack.push(x);
            let top :i32= *self.minstack.last().unwrap();
            if top >= x {
                self.minstack.push(x);
            }
        }
    }
    
    fn pop(&mut self) {
        let x:i32 = *self.stack.last().unwrap();
        self.stack.pop();
        if *self.minstack.last().unwrap() == x {
            self.minstack.pop();
        }
        
    }
    
    fn top(&self) -> i32 {
        // let Some(i) =
       *self.stack.last().unwrap()
    }
    
    fn get_min(&self) -> i32 {
        // let Some(i) =self.MinStack.last();
         *self.minstack.last().unwrap()
    }
}
