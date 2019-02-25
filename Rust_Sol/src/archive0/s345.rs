impl Solution {
    pub fn reverse_vowels(s: String) -> String {
      if s.len() == 0 {
          return "".to_owned();
      }
      unsafe {
        let mut ss = s.clone();
        let mut s = ss.as_bytes_mut();
        let mut start: usize = 0;
        let mut end = s.len() -  1;
        while start < end {
          while start < s.len() && !Solution::is_vowel(s[start]) {
            start += 1
          }
          while end >= 0 && !Solution::is_vowel(s[end]) {
            if end == 0 {
              return String::from_utf8(s.to_vec()).unwrap();
            }
            end -= 1
          }
          if start < end {
            let tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start += 1;
            if end == 0 {
              return String::from_utf8(s.to_vec()).unwrap();
            }
            end -= 1;
          }
        }
        return String::from_utf8(s.to_vec()).unwrap();
      }
      return "".to_owned();
    }

    fn is_vowel(c: u8) -> bool {
      match c {
        b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U' => return true,
        _ => return false,
      }
    }
}