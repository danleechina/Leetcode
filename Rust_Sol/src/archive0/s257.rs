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

struct Solution {

}

use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
      let mut ans: Vec<String> = Vec::new();
      if root.is_none() {
        return ans;
      }
      let sroot: Rc<RefCell<TreeNode>> = root.unwrap();
      let leftRes = {
        let x = (*sroot).borrow().left.clone();
        if x.is_some() {
          Some(Solution::binary_tree_paths(Some(x.unwrap())))
        } else {
          None
        }
      };
      let rightRes = {
        let x = (*sroot).borrow().right.clone();
        if x.is_some() {
          Some(Solution::binary_tree_paths(Some(x.unwrap())))
        } else {
          None
        }
      };
      if rightRes.is_none() && leftRes.is_none() {
        ans.push((*sroot).borrow().val.to_string());
      } else {
        if leftRes.is_some() {
          for mut r in leftRes.unwrap().into_iter() {
            r.insert_str(0, "->");
            r.insert_str(0, &(*sroot).borrow().val.to_string());
            ans.push(r);
          }
        }
        if rightRes.is_some() {
          for mut r in rightRes.unwrap().into_iter() {
            r.insert_str(0, "->");
            r.insert_str(0, &(*sroot).borrow().val.to_string());
            ans.push(r);
          }
        }
      }
      return ans;
    }
}