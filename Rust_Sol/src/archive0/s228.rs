impl Solution {
  pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
    let mut res: Vec<String> = Vec::new();
    if nums.len() == 0 {
      return res;
    }
    let mut start = nums[0];
    if nums.len() == 1 {
      res.push(start.to_string());
      return res;
    }
    let mut curr = start;
    let mut index: usize = 1;
    while index < nums.len() {
      let item = nums[index];
      if item == start {
        continue;
      }
      if item != curr + 1 {
        if start != curr {
          res.push(format!("{}->{}", start, curr));
        } else {
          res.push(start.to_string());
        }
        start = item;
      }
      curr = item;
      index += 1;
      if index == nums.len() {
        if start != curr {
          res.push(format!("{}->{}", start, curr));
        } else {
          res.push(start.to_string());
        }
      }
    }
    return res;
  }
}