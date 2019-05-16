struct Solution {}

use std::cmp::min;
use std::collections::HashMap;
use std::collections::HashSet;
impl Solution {
  pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
    let mut adjs: Vec<HashSet<i32>> = vec![HashSet::new(); n as usize];
    for edge in edges {
      adjs[edge[0] as usize].insert(edge[1]);
      adjs[edge[1] as usize].insert(edge[0]);
    }
    let mut res: Vec<i32> = Vec::new();
    for (index, adj) in adjs.iter().enumerate() {
      if adj.len() <= 1 {
        res.push(index as i32);
      }
    }
    let mut sum = n;
    while sum > 2 {
      let mut new_res: Vec<i32> = Vec::new();
      for v in res.iter() {
        let adj: Vec<i32> = adjs[*v as usize].iter().map(|&x| x).collect();
        for vv in adj {
          adjs[vv as usize].remove(v);
          if adjs[vv as usize].len() == 1 {
            new_res.push(vv);
          }
        }
      }
      sum -= res.len() as i32;
      res = new_res;
    }
    return res;
  }
}
