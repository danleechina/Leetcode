impl Solution {
  pub fn calculate(s: String) -> i32 {
    let s: String = s.split(' ').collect();
    let mut nums: Vec<i32> = Vec::new();
    let mut operations: Vec<char> = Vec::new();
    let mut parseNum = 0;
    let mut is_construte_number = false;
    for (p, c) in s.chars().enumerate() {
      if c.is_ascii_digit() {
        is_construte_number = true;
        parseNum = 10 * parseNum + c.to_digit(10).unwrap() as i32;
      } else {
        if is_construte_number {
          nums.push(parseNum);
        }
        is_construte_number = false;
        if let Some(op) = operations.last() {
          if (*op == '/' || *op == '*') {
            let rhs = nums.pop().unwrap();
            let lhs = nums.pop().unwrap();
            print!("{}{}{}\n", lhs, *op, rhs);
            if *op == '/' {
              nums.push(lhs / rhs);
            } else {
              nums.push(lhs * rhs);
            }
            operations.pop();
          }
        }
        operations.push(c);
        parseNum = 0;
      }
    }
    if is_construte_number {
      nums.push(parseNum);
    }
    if let Some(op) = operations.last() {
      if (*op == '/' || *op == '*') {
        let rhs = nums.pop().unwrap();
        let lhs = nums.pop().unwrap();
        print!("{}{}{}\n", lhs, *op, rhs);
        if *op == '/' {
          nums.push(lhs / rhs);
        } else {
          nums.push(lhs * rhs);
        }
        operations.pop();
      }
    }
    while !operations.is_empty() {
      let op = operations.remove(0);
      let lhs = nums.remove(0);
      let rhs = nums.remove(0);
      print!("{}{}{}\n", lhs, op, rhs);
      if op == '+' {
        nums.insert(0, lhs + rhs);
      } else if op == '-' {
        nums.insert(0, lhs - rhs);
      }
    }
    if nums.is_empty() {
      return 0;
    } else {
      return nums.pop().unwrap();
    }
  }
}