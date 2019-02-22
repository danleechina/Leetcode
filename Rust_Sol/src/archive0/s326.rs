impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
      for i in 0..20 {
        if 3_i32.pow(i) == n {
          return true;
        }
      }
      return false;
    }
}