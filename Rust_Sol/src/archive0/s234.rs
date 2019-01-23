// Definition for singly-linked list.
#[derive(PartialEq, Eq, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

pub struct Solution{}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
impl ListNode {

  pub fn printNode(&self) {
    let mut x: &ListNode = self;
    println!("{}", x.val);
    while let Some(ref nx) = x.next {
      x = nx;
      println!("{}", x.val);
    }
  }

  pub fn len(&self) -> i32 {
    let mut tmp: &ListNode = self;
    let mut res = 1;
    while let Some(ref t) = tmp.next {
      res += 1;
      tmp = t;
    }
    res
  }

  pub fn revese(&mut self) -> &Self {
    return self;
  }

}
impl Solution {
  pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
    if None == head {
      return true;
    }
    let len = head.unwrap().len();
    println!("{}", len);
    let mut half = (len + 1) / 2;
    let mut tail = &head.unwrap();
    while half > 0 {
      tail = &tail.next.unwrap();
      half -= 1;
    }
    tail = tail.revese();
    half = (len + 1) / 2;
    let mut h = &head.unwrap();
    while half > 0 {
      if tail.val != h.val {
        return false;
      } else {
        tail = &tail.next.unwrap();
        h = &h.next.unwrap();
      }
    }
    return true;
  }
}