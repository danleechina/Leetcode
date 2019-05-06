struct Solution {}

impl Solution {
  pub fn is_additive_number(num: String) -> bool {
    if num.is_empty() {
      return false;
    }
    let len = num.len();
    for i in 0..len {
      for j in (i + 1)..len {
        let mut num1_str: String = num.chars().take(i + 1).collect();
        let mut num1_ = num1_str.parse::<i64>();
        if num1_.is_err() {
          return false;
        }
        let mut num1 = num1_.unwrap();
        let mut num2_str: String = num.chars().skip(i + 1).take(j - i).collect();
        let mut num2_ = num2_str.parse::<i64>();
        if num2_.is_err() {
          continue;
        }
        let mut num2 = num2_.unwrap();
        if num1_str.chars().nth(0).unwrap() == '0' && num1 != 0 {
          continue;
        }
        if num2_str.chars().nth(0).unwrap() == '0' && num2 != 0 {
          continue;
        }

        let mut rest_num: String = num.chars().skip(j + 1).collect();
        let mut is_ok = false;
        while !rest_num.is_empty() {
          is_ok = true;
          let mut num3 = num1 + num2;
          let mut num3_str: String = num3.to_string();
          // println!("{},{},{},{}", num1_str, num2_str, num3_str, rest_num);
          if rest_num.chars().nth(0).unwrap() == '0' && num3 != 0 {
            is_ok = false;
            break;
          }
          if rest_num.starts_with(&num3_str[..]) {
            num1 = num2;
            num1_str = num2_str;
            num2 = num3;
            num2_str = num3_str;
            rest_num = rest_num.chars().skip(num2_str.len()).collect();
          } else {
            is_ok = false;
            break;
          }
        }
        if is_ok {
          return true;
        }
      }
    }
    return false;
  }
}
