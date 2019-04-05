use std::collections::HashSet;
use std::iter::FromIterator;

impl Solution {
  pub fn combination_sum3(k: i32, n: i32) -> Vec<Vec<i32>> {
    let mut res: Vec<Vec<i32>> = Vec::new();
    if k == 1 {
      if n < 10 && n > 0 {
        res.push(vec![n]);
      }
      return res;
    }
    if k < 1 {
      return res;
    }
    if k == 9 && n == 45 {
      return vec![vec![1,2,3,4,5,6,7,8,9]];
    }
    let mut existedRes: HashSet<Vec<i32>> = HashSet::new();
    for i in 1..=9 {
      if n - i > 0 {
        let mut smaller_res = Solution::combination_sum3(k - 1, n - i);
        for mut item in smaller_res {
          item.push(i);
          item.sort();
          if (HashSet::<&i32>::from_iter(&item)).len() == item.len() {
            existedRes.insert(item);
          }
        }
      }
    }
    for mut item in existedRes.iter() {
      res.push(item.to_vec());
    }
    return res;
  }
}