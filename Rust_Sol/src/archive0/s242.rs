use std::collections::HashMap;

impl Solution {
    pub fn is_anagram(mut s: String, mut t: String) -> bool {
      if s.len() != t.len() {
        return false;
      }
      unsafe {
        let mut bs = s.as_bytes_mut();
        bs.sort();
        let mut bt = t.as_bytes_mut();
        bt.sort();
        return bs == bt;
      }
      return false;
    }
}