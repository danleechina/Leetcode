impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
      if n < 0 {
        return false;
      }
      let mut twop = 1;
      for x in 0..32 {
        twop = 1<<x;
        if n == twop {
          return true;
        }
      }
      return false;
    }
}