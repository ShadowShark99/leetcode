//2657. Find the Prefix Common Array of Two Arrays
impl Solution {
    pub fn find_the_prefix_common_array(a: Vec<i32>, b: Vec<i32>) -> Vec<i32> {
        let mut aBits: Vec<bool> = Vec::new();
        let mut bBits: Vec<bool> = Vec::new();
        for i in 0..51{
            aBits.push(false);
            bBits.push(false);
        }
        let mut cArr: Vec<i32> = Vec::new();
        let n = a.len();
        for i in 0..n{
            let aVal = (a[i] - 1) as usize;
            let bVal = (b[i] - 1) as usize;
            let mut matches = 0;
            if(aVal == bVal)
            {
                matches = 1;
            }
            else
            {
                if(bBits[aVal])
                {
                    matches = matches + 1;
                }
                if(aBits[bVal])
                {
                    matches = matches + 1;
                }
            }
            
            if(i == 0)
            {
                cArr.push(matches);
            }
            else
            {
                cArr.push(cArr[cArr.len()-1] + matches);
            }

            aBits[aVal] = true;
            bBits[bVal] = true;
            
        }
        return cArr;
    }
}
