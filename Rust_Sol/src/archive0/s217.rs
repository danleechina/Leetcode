pub fn print_hello() {
    println!("Hello, world!");
}
use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
      let len = nums.len();
      let a: HashSet<_> = nums.into_iter().collect();
      a.len() == nums.len()
    }
}