struct Solution {}

use std::collections::HashSet;
impl Solution {
  pub fn num_squares(n: i32) -> i32 {
    let mut q: Vec<(i32, i32)> = Vec::new();
    q.push((n, 0));
    let mut visited: HashSet<i32> = HashSet::new();
    visited.insert(n);
    while !q.is_empty() {
      let (n, step) = q.pop().unwrap();
      let mut i = 1;
      while i * i <= n {
        let diff = n - i * i;
        if diff == 0 {
          return step + 1;
        } else if diff > 0 {
          if !visited.contains(&diff) {
            q.insert(0, (diff, step + 1));
            visited.insert(diff);
          }
        } else {
          break;
        }
        i += 1;
      }
    }
    return 0;
  }
}
