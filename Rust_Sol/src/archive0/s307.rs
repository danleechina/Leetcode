struct NumArray {
  sum_nums: Vec<i32>,
}
use std::cmp::min;
use std::cmp::max;

impl NumArray {

    fn new(nums: Vec<i32>) -> Self {
      return NumArray {
        sum_nums: NumArray::sum(nums),
      };
    }

    fn sum(nums: Vec<i32>) -> Vec<i32> {
      let mut res = vec![0; nums.len()];
      if nums.is_empty() {
        return res;
      }
      let mut i = 1;
      res[0] = nums[0];
      while i < res.len() {
        res[i] = res[i - 1] + nums[i];
        i += 1;
      }
      res
    }
    
    fn update(&mut self, i: i32, val: i32) {
      let old_val: i32;
      let mut i = i as usize;
      if i >= self.sum_nums.len() {
        return;
      }
      if i == 0 {
        old_val = self.sum_nums[i];
      } else {
        old_val = self.sum_nums[i] - self.sum_nums[i - 1];
      }
      let diff = val - old_val;
      while i < self.sum_nums.len() {
        self.sum_nums[i] += diff;
        i += 1;
      }
    }
    
    fn sum_range(&self, i: i32, j: i32) -> i32 {
      if self.sum_nums.is_empty() {
        return 0;
      }
      let mut i = i as usize;
      let mut j = j as usize;
      i = min(i, self.sum_nums.len() - 1);
      j = min(j, self.sum_nums.len() - 1);
      i = max(0, i);
      j = max(0, j);
      if i == 0 {
        return self.sum_nums[j];
      }
      return self.sum_nums[j] - self.sum_nums[i - 1];
    }
}