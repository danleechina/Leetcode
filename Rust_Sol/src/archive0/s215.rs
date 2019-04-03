impl Solution {
  pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
    let mut bigger: Vec<i32> = Vec::new();
    let mut smaller: Vec<i32> = Vec::new();
    let mut equaller: Vec<i32> = Vec::new();
    for (p, i) in nums.iter().enumerate() {
      if nums[0] > *i {
        smaller.insert(0, *i);
      } else if nums[0] < *i {
        bigger.insert(0, *i);
      } else {
        equaller.insert(0, *i);
      }
    }
    let bl = bigger.len() as i32;
    let el = equaller.len() as i32;
    let sl = smaller.len() as i32;

    if k <= bl {
      return Solution::find_kth_largest(bigger, k);
    } else if k > bl && k <= bl + el {
      return *equaller.last().unwrap();
    } else {
      return Solution::find_kth_largest(smaller, k - bl - el);
    }
  }
}