struct Solution {}
use std::cmp::max;

impl Solution {
  pub fn max_product(words: Vec<String>) -> i32 {
    let mut bit_words: Vec<i32> = vec![0; words.len()];
    for (position, word) in words.iter().enumerate() {
      let num_words = word.as_bytes().iter().map(|item| {
        return item - b'a';
      });
      for item in num_words {
        bit_words[position] |= 1 << item;
      }
    }
    let mut res = 0;
    let mut i = 0;
    while i < words.len() {
      let mut j = i + 1;
      while j < words.len() {
        let mut is_duplicate = false;
        for idx in 0..26 {
          if (bit_words[i] & 1 << idx) == (bit_words[j] & 1 << idx) && (bit_words[i] & 1 << idx) > 0
          {
            is_duplicate = true;
            break;
          }
        }
        if !is_duplicate {
          res = max(res, words[i].len() * words[j].len());
        }
        j += 1;
      }
      i += 1;
    }
    return res as i32;
  }
}
