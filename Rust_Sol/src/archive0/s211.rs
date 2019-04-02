use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

struct WordDictionary {
  word_count: i32,
  charToTrie: HashMap<char, WordDictionary>,
}

impl WordDictionary {
  fn new() -> Self {
    return WordDictionary {
      word_count: 0,
      charToTrie: HashMap::new(),
    };
  }

  fn add_word(&mut self, word: String) {
    let mut node = self;
    for (p, c) in word.chars().enumerate() {
      let charToTrie = &mut node.charToTrie;
      match charToTrie.get(&c) {
        Some(_) => node = charToTrie.get_mut(&c).unwrap(),
        None => {
          charToTrie.insert(c, WordDictionary::new());
          node = charToTrie.get_mut(&c).unwrap();
        }
      }
      if p + 1 == word.chars().count() {
        node.word_count += 1;
      }
    }
  }

  fn search(&self, word: String) -> bool {
    let mut node = self;
    for (pos, c) in word.chars().enumerate() {
      match node.charToTrie.get(&c) {
        Some(v) => node = v,
        None => {
          if c == '.' && node.charToTrie.values().len() > 0 {
            for dict in node.charToTrie.values() {
              let substring: String = word.chars().skip(pos + 1).collect();
              if dict.search(substring) {
                return true;
              }
            }
          }
          return false;
        }
      }
    }
    return node.word_count > 0;
  }
}
