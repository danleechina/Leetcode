struct MyQueue {
  internal_list: Vec<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {

    /** Initialize your data structure here. */
    fn new() -> Self {
        return MyQueue {
          internal_list: Vec::new()
        }
    }
    
    /** Push element x to the back of queue. */
    fn push(&mut self, x: i32) {
      self.internal_list.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    fn pop(&mut self) -> i32 {
      self.internal_list.remove(0)
    }
    
    /** Get the front element. */
    fn peek(&self) -> i32 {
      self.internal_list[0]
    }
    
    /** Returns whether the queue is empty. */
    fn empty(&self) -> bool {
      self.internal_list.is_empty()
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * let obj = MyQueue::new();
 * obj.push(x);
 * let ret_2: i32 = obj.pop();
 * let ret_3: i32 = obj.peek();
 * let ret_4: bool = obj.empty();
 */