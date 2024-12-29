//2134. Minimum Swaps to Group All 1's Together II

impl Solution {
    pub fn min_swaps(nums: Vec<i32>) -> i32 {
        let mut count:usize = 0;
        for i in &nums{
            if *i == 1{
                count = count + 1;
            }
        }
        let n = (&nums).len();
        let mut ret: i32 = count.try_into().unwrap();
        let mut zeros = 0;
        let mut l: usize = 0;
        let mut r: usize = count - 1;
        for i in l..(r+1){
            if nums[i] == 0{
                zeros = zeros + 1;
            }
        }
        
        while l != n {
            if zeros < ret{
                ret = zeros;
            }
            if nums[l] == 0{
                zeros = zeros - 1;
            }
            r = (r + 1)% n;
            if nums[r] == 0{
                zeros = zeros + 1;
            }
            l = l+1;
        }
        ret
    }
}
