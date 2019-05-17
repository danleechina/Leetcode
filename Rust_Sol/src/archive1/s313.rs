struct Solution {}
use std::cmp::min;

impl Solution {
  pub fn nth_super_ugly_number(n: i32, primes: Vec<i32>) -> i32 {
    let mut ptrs: Vec<usize> = vec![0; primes.len()];
    let mut uglys: Vec<i32> = vec![1];
    for i in 1..n {
      let mut min_value = uglys[ptrs[0]] * primes[0];
      for j in 1..primes.len() {
        min_value = min(min_value, uglys[ptrs[j]] * primes[j]);
      }

      for j in 0..primes.len() {
        if uglys[ptrs[j]] * primes[j] == min_value {
          ptrs[j] += 1;
        }
      }
      uglys.push(min_value);
    }
    return *uglys.last().unwrap();
  }
}
