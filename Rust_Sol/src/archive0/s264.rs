use std::cmp::min;

impl Solution {
  pub fn nth_ugly_number(n: i32) -> i32 {
    let mut i2 = 0;
    let mut i3 = 0;
    let mut i5 = 0;
    let mut uglys: Vec<i32> = vec![1];
    for index in 1..n {
      let next = min(uglys[i2] * 2, min(uglys[i3] * 3, uglys[i5] * 5));
      if next == uglys[i2] * 2 {
        i2 += 1;
      }
      if next == uglys[i3] * 3 {
        i3 += 1;
      }
      if next == uglys[i5] * 5 {
        i5 += 1;
      }
      uglys.push(next);
    }
    return *uglys.last().unwrap();
  }
}