impl Solution {
    pub fn is_power_of_four(num: i32) -> bool {
        if num == 0 {
            return false;
        }
        if num == 1 {
            return true;
        }
        let mut num = num;
        for index in 0..=15 {
            if num % 4 == 0 {
                num /= 4;
                if num == 1 || num == 0 {
                    return true
                }
            } else {
                return false;
            }
        }
        return true;
    }
}