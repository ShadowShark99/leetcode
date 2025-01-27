//2940. Find Building Where Alice and Bob Can Meet
class Solution {
public:
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[1] > b[1];
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        for(int i = 0; i < q; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            if(x > y)
            {
                queries[i][1] = x;
                queries[i][0] = y;
            }
            queries[i].push_back(i);// keep track of the index at queries[2]
        }
        sort(queries.begin(),queries.end(),comp);
        
        vector<int> maxStack;
        vector<int> mSIndex;
        vector<int> ans(q,-1);

        int h = n - 1;
        for(int i = 0; i < q; i++)
        {
            //get y
            int y = queries[i][1];
            //get x
            int x = queries[i][0];
            //process stack until y
            while(h > y)
            {
                int poop = heights[h];
                //while top of stack is less or equal evaluated index, pop
                while(maxStack.size() > 0 && poop >= maxStack[maxStack.size()-1])
                {
                    maxStack.erase(--maxStack.end());
                    mSIndex.erase(--mSIndex.end());
                }
                maxStack.push_back(poop);
                mSIndex.push_back(h--);
            }
            
            //check if x== y or height[x] < height[y]
            
            if(x == y || heights[x] < heights[y])
                ans[queries[i][2]] = y;
            else{ //binary search for t that height[t] > height[x]
                int l = 0;
                int r = mSIndex.size() - 1;
                while(l <= r)
                {
                    int m = l + (r-l)/2;
                    int mI = mSIndex[m];
                    if(heights[mI] > heights[x])
                        l = m + 1;
                    else
                        r = m - 1;
                }
                if(r == -1)
                    ans[queries[i][2]] = -1;
                else
                    ans[queries[i][2]] = mSIndex[r];
                
                
                
            }
            
        }
        return ans;
    }
};
