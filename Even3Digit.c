class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> counts(10,0);
        for(int num : digits)
        {
            counts[num]++;
        }
        counts[0] = min(2, counts[0]); // at most 2 zeros
        for(int i = 1; i < 10; i++)
            counts[i] = min(3, counts[i]); // ceil 3
        
        vector<int> ans;
        findEven(counts, 0, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }

    //start from ones place
    void findEven(vector<int>& counts, int depth, vector<int>& ans, int curr)
    {
        if(depth == 3)
        {
            ans.push_back(curr);
            return;
        }
        int mult = m(10, depth);
        for(int i = 0; i < 10; i++)
        {
            //counts[i];
            //cout << "depth: " << i << " curr = " << curr << endl; 
            if(depth == 2 && i == 0)
                continue;
            if(counts[i]--)
                findEven(counts, depth + 1, ans, curr + i*mult);
            counts[i]++;
            if(depth == 0)//ones place
                i++; //only evens
            
        }
    }

    //a ^ b
    int m(int a, int b)
    {
        int ret = 1;
        for(int i = 0; i < b; i++)
        {
            ret *= a;
        }
        return ret;
    }
};
