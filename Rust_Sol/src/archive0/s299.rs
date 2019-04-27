struct Solution {}

use std::cmp::min;
impl Solution {
  pub fn get_hint(secret: String, guess: String) -> String {
    let mut guess_chars = guess.chars();
    let mut secret_cnt: Vec<i32> = vec![0; 10];
    let mut guess_cnt: Vec<i32> = vec![0; 10];
    let mut bull_cnt = 0;
    for (p, c) in secret.chars().enumerate() {
      let num_c = c.to_digit(10).unwrap() as usize;
      let gc = guess_chars.next().unwrap();
      let num_gc = gc.to_digit(10).unwrap() as usize;
      if num_gc == num_c {
        bull_cnt += 1;
      } else {
        guess_cnt[num_gc] += 1;
        secret_cnt[num_c] += 1;
      }
    }
    let mut cow_cnt = 0;
    for i in 0..10 {
      cow_cnt += min(secret_cnt[i], guess_cnt[i]);
    }
    return format!("{}A{}B", bull_cnt, cow_cnt);
  }
}
