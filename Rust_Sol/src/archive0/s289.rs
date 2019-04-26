struct Solution {}

impl Solution {
  pub fn game_of_life(board: &mut Vec<Vec<i32>>) {
    let m = board.len();
    if m == 0 {
      return;
    }
    let n = board[0].len();
    for i in 0..m {
      for j in 0..n {
        board[i][j] <<= 1;
      }
    }
    for i in 0..m {
      for j in 0..n {
        let mut living_cnt = 0;
        if i > 0 && (board[i - 1][j] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if i + 1 < m && (board[i + 1][j] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if i > 0 && j > 0 && (board[i - 1][j - 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if i + 1 < m && j + 1 < n && (board[i + 1][j + 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if j > 0 && (board[i][j - 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if j + 1 < n && (board[i][j + 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if i + 1 < m && j > 0 && (board[i + 1][j - 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }
        if i > 0 && j + 1 < n && (board[i - 1][j + 1] >> 1 & 1 == 1) {
          living_cnt += 1;
        }

        if living_cnt < 2 {

        } else if (living_cnt == 2 || living_cnt == 3) && board[i][j] >> 1 & 1 == 1 {
          board[i][j] ^= 1;
        } else if living_cnt > 3 {

        } else if living_cnt == 3 && board[i][j] >> 1 & 1 != 1 {
          board[i][j] ^= 1;
        }

        // if living_cnt == 2 && living_cnt == 3 {
        //   if board[i][j] >> 1 & 1 == 1 || living_cnt == 3 {
        //     board[i][j] ^= 1;
        //   }
        // }
      }
      println!("");
    }
    for i in 0..m {
      for j in 0..n {
        board[i][j] &= 1;
      }
    }
  }
}
