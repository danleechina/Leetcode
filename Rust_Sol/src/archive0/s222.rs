
use std::rc::Rc;
use std::cell::RefCell;


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


impl Solution {
  pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    match root {
      Some(node) => {
        let leftCnt: i32;
        if let Some(left) =  &node.borrow().left {
          leftCnt = Solution::count_nodes(Some(Rc::clone(left)));
        } else {
          leftCnt = 0;
        }
        let rightCnt: i32;
        if let Some(right) =  &node.borrow().right {
          rightCnt = Solution::count_nodes(Some(Rc::clone(right)));
        } else {
          rightCnt = 0;
        }
        return rightCnt + leftCnt + 1;
        // return Solution::count_nodes(Rc::clone(node).borrow().left) + 
        // Solution::count_nodes(Rc::clone(node).borrow().right) + 1;
      },
      None => return 0
    }
  }
}