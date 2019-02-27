impl Solution {
  pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    let mut res: Vec<i32> = Vec::new();
    let mut nums1 = nums1;
    let mut nums2 = nums2;
    nums1.sort();
    nums2.sort();
    let mut index1: usize = 0;
    let mut index2: usize = 0;
    let len1 = nums1.len();
    let len2 = nums2.len();
    while index1 < len1 {
      while index2 < len2 {
        if nums1[index1] == nums2[index2] {
          res.push(nums1[index1]);
          index2 += 1;
          break;
        } else if nums1[index1] < nums2[index2] {
          break;
        }
        index2 += 1;
      }
      index1 += 1;
    }
    return res;
  }
}