struct Solution {}

impl Solution {
  pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
    let mut all = 0;
    for item in nums.iter() {
      all ^= *item;
    }
    let mut n = 0;
    while (all >= 0 && all >> n != 0) || (all < 0 && (!all >> n) != 0) {
      n += 1;
    }
    n -= 1;
    let mut r1 = 0;
    let mut r2 = 0;
    for item in nums.iter() {
      if all >= 0 {
        if (*item) >> n & 1 != 0 {
          r1 ^= item;
        } else {
          r2 ^= item;
        }
      } else {
        if *item < 0 && ((*item) >> n & -1 != 0) {
          r1 ^= item;
        } else {
          r2 ^= item;
        }
      }
    }
    return vec![r1, r2];
  }
}
