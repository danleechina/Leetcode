impl Solution {
    pub fn is_ugly(num: i32) -> bool {
        if num <= 0 {
            return false;
        }
        let mut cp = num;
        while cp % 2 == 0 {
            cp /= 2;
        }
        while cp % 3 == 0 {
            cp /= 3;
        }
        while cp % 5 == 0 {
            cp /= 5;
        }
        return cp == 1;
    }
}