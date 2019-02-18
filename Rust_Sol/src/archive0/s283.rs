impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        nums.sort_by(|a, b| {
          if *a == 0 || *b == 0 {
            if *a == 0 {
              return std::cmp::Ordering::Greater;
            } else {
              return std::cmp::Ordering::Less;
            }
          } else {
            return std::cmp::Ordering::Equal;
          }
        });
    }
}