//2127. Maximum Employees to Be Invited to a Meeting
class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<bool> visited(n, false);
        vector<int> foundCycleLength(n, 0);
        int maxCycle = 0;
        //int currCycle = 0;
        set<int> couples;
        vector<int> depth(n, -1);
        for(int i = 0; i < n; i++)
        {
            
            if(!visited[i])
            {
                //cout << "Starting at node: " << i << endl;
                //reset depth array we need to afind a way to only update the depth we have found
                maxCycle = max(maxCycle,findCycle(visited,depth,foundCycleLength,i,0,favorite, couples));
            }
        }
        // for(int cl : foundCycleLength)
        // {
        //     cout << cl << endl;
        // }
        int acyclicChains = 0;
        vector<vector<int>> revFav(n); //reverse graph
        for(int i = 0; i < n; i++)
        {
            revFav[favorite[i]].push_back(i);
        }
        for(auto it = couples.begin(); it != couples.end(); it++)
        {
            int a = *it;
            int b = favorite[a];
            int maxA = 0;
            int maxB = 0;
            //cout << "a: " << a << " b: " << b << endl;
            for(int node : revFav[a])
            {
                if(node != b)
                {
                    maxA = max(maxA,revDepth(revFav,node)+1);
                }
            }
            for(int node : revFav[b])
            {
                if(node != a)
                {
                    maxB = max(maxB,revDepth(revFav,node)+1);
                }
            }
            //chains found
            acyclicChains = acyclicChains + 2 + maxA + maxB;
        }
        return max(acyclicChains,maxCycle);
    }

    int findCycle(vector<bool>& visited, vector<int>& depth,
vector<int>& fCL,int i, int d, vector<int>& favorite,set<int>& c)
    {
        //cout << "Processing node: " << i << endl;
        if(fCL[i] != 0)
        {
            return fCL[i];
        }
        if(depth[i] != -1 || !visited[i])
        {
            visited[i] = true;
            if(depth[i] == -1)
            {
                depth[i] = d;
                return fCL[i] = findCycle(visited, depth, fCL,favorite[i],d + 1,favorite,c);
            }
                if(d - depth[i] == 2) //two cycle
                {
                    c.insert(i);
                }
                //cout << "found cycle of length: " <<  d - depth[i] << endl;
                return d - depth[i];
        }
        return fCL[i];

    }

    int revDepth(vector<vector<int>>& revFav, int i)
    {
        int maxDepth = 0;
        for(int u : revFav[i])
        {
            maxDepth = max(maxDepth,revDepth(revFav, u)+1);
        }
        return maxDepth;
    }
};

    
