use std::cmp::max;
use std::cmp::min;
impl Solution {
  pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
    let n = matrix.len();
    if n == 0 {
      return 0;
    }
    let m = matrix[0].len();
    // if m == 0 {
    //   return 0;
    // }
    let mut dp = vec![vec![0; m + 1]; n + 1];
    let mut res = 0;
    for i in 1..=n {
      for j in 1..=m {
        if matrix[i - 1][j - 1] == '1' {
          dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
          res = max(dp[i][j], res);
        }
      }
    }
    return res * res;
  }
}