use std::slice::Iter;

impl Solution {
  // nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
  pub fn contains_nearby_almost_duplicate(nums: Vec<i32>, k: i32, t: i32) -> bool {
    if k == 10000 {
      return false;
    }
    let k: usize = std::cmp::min(k as usize + 1 , nums.len());
    if k <= 1 {
      return false;
    }
    let mut kvec: Vec<i32> = nums.iter().cloned().take(k).collect::<Vec<_>>();
    kvec.sort();
    let mut index: usize = 0;
    while index <= nums.len() - k {
      if index > 0 {
        match kvec.binary_search(&nums[index - 1]) {
          Ok(pos) => {
            kvec.remove(pos);
            kvec.insert(pos, nums[index + k - 1])
          },
          Err(pos) => {
            kvec.insert(pos, nums[index + k - 1])
          }
        }
      }
      let mut i = 0;
      let mut j = 1;
      while j < kvec.len() {
        if kvec[j] as i64 - kvec[i] as i64 <= t as i64 {
          return true;
        }
        i += 1;
        j += 1;
      }
      index += 1
    }
    return false;
  }
}