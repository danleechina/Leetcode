struct Solution {}

use std::cmp::max;
impl Solution {
  pub fn max_profit(prices: Vec<i32>) -> i32 {
    if prices.len() < 2 {
      return 0;
    }
    let mut pre_buy = -prices[0];
    let mut pre_sell = 0;
    let mut pre_rest = 0;
    let mut buy = max(-prices[0], -prices[1]);
    let mut sell = prices[1] - prices[0];
    let mut rest = 0;
    for (p, price) in prices.iter().enumerate() {
      if p < 2 {
        continue;
      }
      let pb = buy;
      let ps = sell;
      let pr = rest;
      pre_rest = rest;
      rest = max(max(pb, ps), pr);
      pre_sell = sell;
      sell = max(pb + price, ps);
      pre_buy = buy;
      buy = max(pr - price, pb);
      println!("{},{},{}", buy, sell, rest);
    }
    return max(buy, max(sell, rest));
  }
}
