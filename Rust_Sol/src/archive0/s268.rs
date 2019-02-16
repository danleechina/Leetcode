impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut currentNum = 0;
        let mut ret = 0;
        for &num in nums.iter() {
            ret += currentNum - num;
            currentNum += 1;
        }
        ret += nums.len() as i32;
        return ret;
    }
}