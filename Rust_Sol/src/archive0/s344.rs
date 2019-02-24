// impl Solution {
//     pub fn reverse_string(s: &mut Vec<char>) {
//         let mlen = s.len()/2;
//         let len = s.len();
//         let mut tmp = ' ';
//         for index in 0..mlen {
//             tmp = s[index];
//             s[index] = s[len - 1 - index];
//             s[len - 1 - index] = tmp;
//         }
//     }
// }

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        s.reverse();
    }
}