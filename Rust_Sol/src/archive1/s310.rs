struct Solution {}

use std::cmp::min;
use std::collections::HashSet;
impl Solution {
  pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
    let mut res: Vec<i32> = Vec::new();
    if n == 0 {
      return res;
    }
    for i in 0..=n - 1 {
      res.push(Solution::height_for_root(n, i, &edges));
    }
    let mut minValue = res[0];
    for i in res.iter() {
      minValue = min(minValue, *i);
    }
    let mut nodes: Vec<i32> = Vec::new();
    for (index, item) in res.iter().enumerate() {
      if *item == minValue {
        nodes.push(index as i32);
      }
    }
    return nodes;
  }

  pub fn height_for_root(node_cnt: i32, root: i32, edges: &Vec<Vec<i32>>) -> i32 {
    let mut nodes: Vec<i32> = Vec::new();
    let mut visited: HashSet<i32> = HashSet::new();
    let mut length = 0;
    nodes.push(root);
    visited.insert(root);
    while visited.len() != node_cnt as usize {
      let mut new_nodes: Vec<i32> = Vec::new();
      while !nodes.is_empty() {
        let current_v = nodes.remove(0);
        for edge in edges.iter() {
          let v1 = edge[0];
          let v2 = edge[1];
          if current_v == v1 {
            if !visited.contains(&v2) {
              new_nodes.push(v2);
              visited.insert(v2);
            }
          } else if current_v == v2 {
            if !visited.contains(&v1) {
              new_nodes.push(v1);
              visited.insert(v1);
            }
          }
        }
      }
      nodes = new_nodes;
      length += 1;
    }
    return length;
  }
}
