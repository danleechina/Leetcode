impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len() as i32;
        if n == 0 {
            return Vec::new();
        }
        let mut x = 0;
        let mut y = 0;
        let mut x_cnt = 0;
        let mut y_cnt = 0;
        for item in nums.iter() {
            if (x_cnt != 0 && *item == x)  || (x_cnt == 0 && *item != y) {
                x_cnt += 1;
                x = *item;
            } else if (y_cnt != 0 && *item == y) || y_cnt == 0 {
                y_cnt += 1;
                y = *item;
            } else {
                y_cnt -= 1;
                x_cnt -= 1;
            }
        }
        let mut cnt = 0;
        if x_cnt > 0 {   
            for num in nums.iter() {
                if *num == x {
                    cnt += 1;
                }
            }
        }
        let mut res: Vec<i32> = Vec::new();
        if cnt > n /3 {
            res.push(x);
        }
        cnt = 0;
        for num in nums.iter() {
            if *num == y {
                cnt += 1;
            }
        }
        if cnt > n / 3 {
            res.push(y);
        }
        return res;
    }
}