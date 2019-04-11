use std::cmp::min;
use std::cmp::max;

impl Solution {
  pub fn compute_area(a: i32, b: i32, c: i32, d: i32, e: i32, f: i32, g: i32, h: i32) -> i32 {
    let x1 = c - a;
    let y1 = d - b;
    let x2 = g - e;
    let y2 = h - f;
    let x3 = if min(c, g) > max(a, e) { min(c, g) - max(a, e) } else {0};
    let y3 = if min(d, h) > max(b, f) { min(d, h) - max(b, f) } else {0};
    let s1 = x1 * y1;
    let s2 = x2 * y2;
    return s1 - x3 * y3 + s2;
  }
}