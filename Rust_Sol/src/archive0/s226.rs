// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}

pub struct Solution {}
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
      match root {
        Some(v) => {
          let b = Rc::clone(&v);
          let mut v = v.borrow_mut();
          let mut vl: Option<Rc<RefCell<TreeNode>>> = None;
          let mut vr: Option<Rc<RefCell<TreeNode>>> = None;
          if let Some(lef) = &v.left {
            vl = Some(Rc::clone(lef));
            Solution::invert_tree(Some(Rc::clone(lef)));
          }
          if let Some(right) = &v.right {
            vr = Some(Rc::clone(right));
            Solution::invert_tree(Some(Rc::clone(right)));
          }
          v.left = vr;
          v.right = vl;
          return Some(b);
        },
        None => return None
      }
    }
}