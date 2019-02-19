use std::collections::HashMap;
impl Solution {
    pub fn word_pattern(pattern: String, str: String) -> bool {
      let items: Vec<_> = str.split(" ").collect();
      if items.len() != pattern.len() {
        return false;
      }
      let mut tmap: HashMap<char, String> = HashMap::new();
      let mut p = pattern.chars();
      for index in 0..items.len() {
        let k = p.next();
        if let Some(v) = tmap.get(&k.unwrap()) {
          if v != items[index] {
            return false;
          }
        } else {
          tmap.insert(k.unwrap(), items[index].to_string());
        }
      }
      p = pattern.chars();
      let mut fmap: HashMap<String, char> = HashMap::new();
      for index in 0..items.len() {
        let k = p.next();
        if let Some(v) = fmap.get(&items[index].to_string()) {
          if *v != k.unwrap() {
            return false;
          }
        } else {
          fmap.insert(items[index].to_string(), k.unwrap());
        }
      }
      return true;
    }
}