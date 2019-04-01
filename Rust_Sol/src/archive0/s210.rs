impl Solution {
  pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {      
    let mut degree = vec![0; num_courses as usize];
    for element in &prerequisites {
      degree[element[0] as usize] += 1;
    }
    let mut vertex: Vec<i32> = Vec::new();
    for (index, ele) in degree.iter().enumerate() {
      if *ele == 0 {
        vertex.push(index as i32);
      }
    }
    let mut topSortRes: Vec<i32> = Vec::new();
    while vertex.len() != 0 {
      let t = vertex.pop().unwrap();
      topSortRes.push(t);
      for element in &prerequisites {
        if element[1] == t {
          degree[element[0] as usize] -= 1;
          if degree[element[0] as usize] == 0 {
            vertex.push(element[0]);
          }
        }
      }
    }
    if topSortRes.len() == num_courses {
      return topSortRes;
    }
    return Vec::new();
  }
}