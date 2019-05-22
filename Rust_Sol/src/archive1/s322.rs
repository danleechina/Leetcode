struct Solution {}

use std::cmp::min;
impl Solution {
  pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
    let mut dp: Vec<i32> = vec![-1; amount as usize + 1];
    dp[0] = 0;
    for index in 1..=amount {
      for coin in coins.iter() {
        let diff = index - *coin;
        if diff >= 0 && dp[diff as usize] != -1 {
          if dp[index as usize] == -1 {
            dp[index as usize] = dp[diff as usize] + 1;
          } else {
            dp[index as usize] = min(dp[index as usize], dp[diff as usize] + 1);
          }
        }
      }
    }
    // for v in dp.iter() {
    //   print!("{} ", v);
    // }
    return dp[amount as usize];
  }
}
