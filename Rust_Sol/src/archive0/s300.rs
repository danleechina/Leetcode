impl Solution {
  pub fn length_of_lis(nums: Vec<i32>) -> i32 {
    if nums.is_empty() {
      return 0;
    }
    let mut res: Vec<i32> = vec![1; nums.len()];
    let mut current = 1;
    while current < nums.len() {
      let mut j = 0;
      while j < current {
        if nums[current] > nums[j] {
          res[current] = std::cmp::max(res[current], res[j] + 1);
        }
        j += 1;
      }
      current += 1;
    }
    current = 0;
    let mut res_max = res[0];
    while current < res.len() {
      res_max = std::cmp::max(res[current], res_max);
      current += 1;
    }
    return res_max;   
  }
}