pub struct Solution;

impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let trimmed = s.trim_end();

        let length = trimmed.len();
        let s_bytes = trimmed.as_bytes();
        for i in (0..length).rev() {
            if s_bytes[i] == b' ' {
                return (length - i - 1) as i32;
            }
        }

        length as i32
    }
}

fn main() {
    let s = String::from("Hello World");
    let result = Solution::length_of_last_word(s);

    println!("{}", result); // Output: 5
}
