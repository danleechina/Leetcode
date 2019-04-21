struct Solution {}

impl Solution {
  pub fn h_index(citations: Vec<i32>) -> i32 {
    let mut res = 0;
    let mut citations = citations;
    citations.sort();
    let len = citations.len();
    for (index, item) in citations.iter().enumerate() {
      let item = *item as usize;
      if item == 0 {
        continue;
      }
      if index + item - 1 < len {
        if citations[index + item - 1] >= item as i32 {
          res = item;
        }
      } else {
        if len - index <= item && res < len - index {
          res = len - index;
        }
        return res as i32;
      }
    }
    return res as i32;
  }
}
