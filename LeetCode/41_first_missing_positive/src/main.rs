pub struct Solution;

impl Solution {
    pub fn first_missing_positive(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut nums = nums;

        for i in 0..n {
            while nums[i] > 0 && (nums[i] as usize) <= n && nums[i] != nums[nums[i] as usize - 1] {
                let target_index = nums[i] as usize - 1;
                nums.swap(i, target_index);
            }
        }

        for (i, &val) in nums.iter().enumerate() {
            if val != (i as i32) + 1 {
                return (i as i32) + 1;
            }
        }

        (n as i32) + 1
    }
}

fn main() {
    let nums = vec![3, 4, 2, 1];
    let result = Solution::first_missing_positive(nums);

    println!("The first missing positive integer is: {}", result);
}
