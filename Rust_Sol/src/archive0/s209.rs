// struct Solution {

// }

impl Solution {
    pub fn min_sub_array_len(s: i32, nums: Vec<i32>) -> i32 {
        if nums.len() == 0 {
            return 0;
        }
        let mut res = 0;
        let mut sum = 0;
        let mut i = 0;
        let mut j = 0;
        while (j < nums.len()) {
            sum += nums[j];
            if sum >= s {
                if res < j - i + 1 && res != 0 {
                    res = res;
                } else {
                    res = j - i + 1;
                }
                // res = res < j - i + 1 && res != 0 ? res : j - i + 1;
                sum -= nums[i];
                sum -= nums[j];
                i += 1;
                j -= 1;
            }
            j += 1;
        }
        return res as i32;
    }
}