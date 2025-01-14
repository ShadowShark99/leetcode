//3223. Minimum Length of String After Operations
impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut v: Vec<i32> = Vec::new();
        for i in 0..26{
            v.push(0);
        }

        for c in s.chars(){
            v[((c as i32) - 97) as usize] = v[((c as i32) - 97) as usize]+1;
        }

        let mut ret = 0;
        for i in v{
            if(i != 0)
            {
                if(i % 2 == 0)
                {
                    ret = ret + 2;
                }
                else
                {
                    ret = ret + 1;
                }
                
            }
        }
        return ret;

    }
}
