impl Solution {
  pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let mut output: Vec<i32> = vec!(1; nums.len());
    let mut all = 1;
    for (pos, item) in nums.iter().enumerate() {
      if pos != 0 {
        all *= nums[pos - 1];
      }
      output[pos] = all;
    }
    all = 1;
    let mut nums = nums;
    nums.reverse();
    for (pos, item) in nums.iter().enumerate() {
      if pos != 0 {
        all *= nums[pos - 1];
      }
      output[nums.len() - pos - 1] *= all;
    }
    return output;
  }
}