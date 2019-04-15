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

use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
    return Solution::Kth(root, k)[k as usize - 1];
  }

  pub fn Kth(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> Vec<i32> {
    let mut vals: Vec<i32> = Vec::new();
    match root {
      Some(node) => {
        let v = node.borrow();
        let mut vl: Option<Rc<RefCell<TreeNode>>> = None;
        if let Some(lef) = &v.left {
          vl = Some(Rc::clone(lef));
          let mut res = Solution::Kth(vl, k);
          vals.append(&mut res);
        }
        if vals.len() == k as usize {
          return vals;
        }
        vals.push(v.val);
        let mut vr: Option<Rc<RefCell<TreeNode>>> = None;
        if let Some(right) = &v.right {
          vr = Some(Rc::clone(right));
          let mut res = Solution::Kth(vr, k);
          vals.append(&mut res);
        }
        return vals;
      },
      None => {
        return vals;
      }
    }
  }
}