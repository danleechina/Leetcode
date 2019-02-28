impl Solution {
  pub fn is_perfect_square(num: i32) -> bool {
    if num < 0 {
      return false;
    }
    let num: i64 = num.into();
    let mut start: i64 = 0;
    let mut end: i64 = num;
    let mut mid = (start + end)/2;
    while (start <= end) {
      if mid * mid < num {
        start = mid + 1;
      } else if mid * mid > num {
        end = mid - 1;
      } else {
        return true;
      }
      mid = (start + end)/2;
    }
    return false;
  }
}