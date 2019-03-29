use std::cell::RefCell;
use std::collections::HashMap;
use std::rc::Rc;

struct Trie {
  word_count: i32,
  charToTrie: HashMap<char, Trie>,
}

impl Trie {
  fn new() -> Self {
    return Trie {
      word_count: 0,
      charToTrie: HashMap::new(),
    };
  }

  fn insert(&mut self, word: String) {
    let mut node = self;
    for (p, c) in word.chars().enumerate() {
      let charToTrie = &mut node.charToTrie;
      match charToTrie.get(&c) {
        Some(_) => node = charToTrie.get_mut(&c).unwrap(),
        None => {
          charToTrie.insert(c, Trie::new());
          node = charToTrie.get_mut(&c).unwrap();
        }
      }
      if p + 1 == word.chars().count() {
        node.word_count += 1;
      }
    }
  }

  fn search(&self, word: String) -> bool {
    let node = self.get_leaf(word);
    return node.is_some() && node.unwrap().word_count > 0;
  }

  fn starts_with(&self, prefix: String) -> bool {
    return self.get_leaf(prefix).is_some();
  }

  fn get_leaf(&self, prefix: String) -> Option<&Trie> {
    let mut node = self;
    for c in prefix.chars() {
      match node.charToTrie.get(&c) {
        Some(v) => node = v,
        None => return None,
      }
    }
    return Some(node);
  }
}
