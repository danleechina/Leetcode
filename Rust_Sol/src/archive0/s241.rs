struct Solution {}

impl Solution {
  pub fn diff_ways_to_compute(input: String) -> Vec<i32> {
    // println!("{}", input);
    let mut res: Vec<i32> = Vec::new();
    for (p, c) in input.chars().enumerate() {
      if c == '+' || c == '-' || c == '*' {
        let res_left = Solution::diff_ways_to_compute(input.chars().take(p).collect());
        let res_right = Solution::diff_ways_to_compute(input.chars().skip(p + 1).collect());
        for left in res_left {
          for right in res_right.iter() {
            if c == '+' {
              res.push(left + *right);
            } else if c == '-' {
              res.push(left - *right);
            } else {
              res.push(left * *right);
            }
          }
        }
      }
    }
    if let Ok(x) = input.parse::<i32>() {
      res.push(x);
    }
    res.sort();
    return res;
  }
}
