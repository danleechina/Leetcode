struct MyStack {
    internal_list: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyStack {

    /** Initialize your data structure here. */
    fn new() -> Self {
        let internal_list = Vec::new();
        return MyStack{
            internal_list
        }
    }
    
    /** Push element x onto stack. */
    fn push(&mut self, x: i32) {
        self.internal_list.push(x)
    }
    
    /** Removes the element on top of the stack and returns that element. */
    fn pop(&mut self) -> i32 {
        match self.internal_list.pop() {
            Some(r) => return r,
            None => panic!("bug!!!!")
        }
    }
    
    /** Get the top element. */
    fn top(& self) -> i32 {
        match self.internal_list.last() {
            Some(r) => return *r,
            None => panic!("bugnnn!!!")
        }
    }
    
    /** Returns whether the stack is empty. */
    fn empty(&self) -> bool {
        self.internal_list.is_empty()
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * let obj = MyStack::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: bool = obj.empty();
 */