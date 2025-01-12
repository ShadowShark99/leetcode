//1400. Construct K Palindrome Strings

impl Solution {
    pub fn can_construct(s: String, k: i32) -> bool {
        let n: i32 = s.len().try_into().unwrap();
        if(k > n)
        {
            return false;
        }
        else
        {
            let mut v: Vec<i32> = Vec::new();
            for i in 0..26{
                v.push(0);
            }
            for c in s.chars(){
                let intC = c as u32;
                let a = 'a' as u32;
                println!("{a:?}");
                let currChar = intC - a;
                let currChar: usize = currChar.try_into().unwrap();
                
                v[currChar] = v[currChar]+ 1;
               // vAtChar = vAtChar + 1;
            }
            let mut oddFound = false;
            let mut min = 1;
            for i in &v{
                let o = (i % 2 == 1);
                //println!("{i}{o}");
                if(o)
                {
                    if(oddFound)
                    {
                        min = min + 1;
                        //println!("{n}");
                    }
                    else
                    {
                        oddFound = true;
                    }
                }

            }
            return min <= k;
        }
    }
}
