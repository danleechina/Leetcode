impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
      let size = nums.len();
      for (i, num) in nums.iter().enumerate() {
        for j in 1..=k as usize {
          if i + j < size && nums[j + i] == nums[i] {
            return true;
          }
        }
      }
      false
    }
}