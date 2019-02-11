// Definition for singly-linked list.
#[derive(PartialEq, Eq, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }

struct Solution{}

impl Solution {
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
      if (head == None) { return true; }
      let mut vec = Vec::new();
      let mut current = head;
      while let Some(node) = current {
        vec.push(node.val);
        current = node.next;
      }
      let mut back = vec.len()/2;
      let mut front = vec.len()/2 - 1;
      if vec.len() % 2 == 1 {
        front = vec.len()/2;
      }
      while front >= 0 {
        if vec[front] != vec[back] {
          return false;
        }
        if front == 0 {
            return true;
        }
        front -= 1;
        back += 1;
      }
      return true;
    }
}