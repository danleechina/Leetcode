impl Solution {
    pub fn find_duplicate(nums: Vec<i32>) -> i32 {
      let mut i = 0;
      let mut j = i + 1;
      while i < nums.len() {
        j = i + 1;
        while j < nums.len() {
          if nums[i] == nums[j] {
            return nums[i];
          }
          j += 1;
        }
        i += 1;
      }
      return -1;
    }
}