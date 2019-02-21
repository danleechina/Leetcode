struct NumArray {
  pub nums: Vec<i32>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumArray {

    fn new(nums: Vec<i32>) -> Self {
      NumArray {
        nums: nums,
      }
    }
    
    fn sum_range(&self, i: i32, j: i32) -> i32 {
      let mut res = 0;
      for index in i..=j {
        res += self.nums[index as usize];
      }
      return res;
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * let obj = NumArray::new(nums);
 * let ret_1: i32 = obj.sum_range(i, j);
 */