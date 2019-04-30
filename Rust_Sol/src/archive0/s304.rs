use std::cmp::min;
use std::cmp::max;

struct NumMatrix {
  sum_matrix: Vec<Vec<i32>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl NumMatrix {

    fn new(matrix: Vec<Vec<i32>>) -> Self {
      let mut sum_matrix: Vec<Vec<i32>> = matrix;
      let row_cnt = sum_matrix.len();
      if row_cnt == 0 {
        return NumMatrix {
          sum_matrix: sum_matrix,
        };
      }
      let col_cnt = sum_matrix[0].len();
      let mut i = 0;
      while i < row_cnt {
        let mut j = 0;
        while j < col_cnt {
          let mut res_ij = sum_matrix[i][j];
          if i > 0 {
            res_ij += sum_matrix[i - 1][j];
          }
          if j > 0 {
            res_ij += sum_matrix[i][j - 1];
          }
          if i > 0 && j > 0 {
            res_ij -= sum_matrix[i - 1][j - 1];
          }
          sum_matrix[i][j] = res_ij;
          j += 1;
        }
        i += 1;
      }
      return NumMatrix {
        sum_matrix: sum_matrix,
      };
    }
    
    fn sum_region(&self, row1: i32, col1: i32, row2: i32, col2: i32) -> i32 {
      let m = self.sum_matrix.len();
      if m == 0 {
        return 0;
      }
      let n = self.sum_matrix[0].len();
      if n == 0 {
        return 0;
      }
      
      let mut row1 = max(row1, 0) as usize;
      let mut row2 = max(row2, 0) as usize;
      let mut col1 = max(col1, 0) as usize;
      let mut col2 = max(col2, 0) as usize;
      row1 = min(m, row1);
      row2 = min(m, row2);
      col1 = min(n, col1);
      col2 = min(n, col2);
      let mut res = self.sum_matrix[row2][col2];
      if row1 == 0 && col1 == 0 {
        return res;
      }
      if row1 == 0 {
        res -= self.sum_matrix[row2][col1 - 1];
        return res;
      }
      if col1 == 0 {
        res -= self.sum_matrix[row1 - 1][col2];
        return res;
      }
      res -= self.sum_matrix[row1 - 1][col2];
      res -= self.sum_matrix[row2][col1 - 1];
      res += self.sum_matrix[row1 - 1][col1 - 1];
      return res;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * let obj = NumMatrix::new(matrix);
 * let ret_1: i32 = obj.sum_region(row1, col1, row2, col2);
 */