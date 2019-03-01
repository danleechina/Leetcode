impl Solution {
    pub fn get_sum(a: i32, b: i32) -> i32 {
      println!("{:b}, {:b}", get_complement(a), get_complement(b));
      return get_complement(add(get_complement(a), get_complement(b)));
    }
}

fn get_complement(a: i32) -> i32 {
  if a >= 0 {
    return a;
  }
  return add(get_inverse(a), 1);
}

fn get_inverse(a: i32) -> i32 {
  return !a;
}

fn add(a: i32, b: i32) -> i32 {
  let mut carry = 0;
  let mut res = 0;
  for ii in 0..32 {
    let mut i = (1<<ii & a) >> (ii);
    let mut j = (1<<ii & b) >> (ii);
    // println!("{:}, {:}", i, j);
    if (i == 0 && j == 0) {
      i = 0;
      j = 0;
    } else if (i == 1 && j == 1) {
      i = 0;
      j = 1;
    } else {
      i = 1;
      j = 0;
    }
    if carry == 1 {
      if i == 0 {
        i = 1;
      } else {
        i = 0;
        j = 1;
      }
    }
    res |= i<<ii;
    carry = j;
  }
  return res;
}