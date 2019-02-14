impl Solution {
  pub fn add_digits(num: i32) -> i32 {
    if num < 10 {
      return num;
    }
    let mut cp = num;
    let mut sum = 0;
    while cp > 0 {
      sum += cp % 10;
      cp /= 10;
    }
    return Solution::add_digits(sum);
  }
}