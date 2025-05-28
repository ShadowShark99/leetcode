//3372. Maximize the Number of Target Nodes After Connecting Trees I

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        //adj matrix
        //int n = edges1.size();
        //int m = edges2.size();
        int man = 0;
        int mam = 0;
        for(vector<int> ab: edges1)
        {
            int a = ab[0];
            int b = ab[1];
            man = max(man, max(a,b));
        }
        for(vector<int> uv: edges2)
        {
            int u = uv[0];
            int v = uv[1];
            mam = max(mam, max(u,v));
        }
        int n = man + 1;
        int m = mam + 1;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(m);
        //1st adj
        
        for(vector<int> ab : edges1)
        {
            int a = ab[0];
            int b = ab[1];
            //cout << "a: " << a << "b: " << b << "test\n";
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        //2nd adj
        for(vector<int> uv : edges2)
        {
            
            int u = uv[0];
            int v = uv[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        //maxDepthArrays
        vector<int> maxDepth1(n);
        vector<int> maxDepth2(m);

        //cout << "test/n";
        //find for each node i: max Nodes reachable from i  at depth k
        for(int i = 0; i < n; i++)
        {  
            maxDepth1[i] = bfsMaxDepth(adj1, k, i);
        }
        

        //find for each node i: max Nodes reachable from i  at depth k - 1
        //also! keep trrack of max node
        int max2 = -1;
        for(int i = 0; i < m; i++)
        {  
            maxDepth2[i] = bfsMaxDepth(adj2, k-1, i);
            max2 = (maxDepth2[i] > max2) ? maxDepth2[i] : max2;
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            ans[i] = maxDepth1[i] + max2;
        }
        return ans;

    }

    struct bfsNode{
        int val;
        int depth;
    };
    //i is initial node
    //return maxNum of nodes reachable at maxDepth
    int bfsMaxDepth(vector<vector<int>>&adj, int maxDepth, int i)
    {
        queue<bfsNode> q;
        bfsNode b;
        b.val = i;
        b.depth = 0;
        //first depth of 0
        if(maxDepth == -1)
            return 0;
        q.push(b);
        vector<bool> visited(adj.size(), false);
        visited[i] = true;
        int ret = 1; //always at least one(itself)
        while(!q.empty()){
            //s for source
            bfsNode b = q.front();
            q.pop();
            int s = b.val;
            int depth = b.depth;
            //cout << depth << "/n";
            if(depth == maxDepth)
                continue;
            for(int c : adj[s])
            {
                if(visited[c])
                    continue;
                visited[c] = true;
                bfsNode p;
                p.val = c;
                p.depth = depth + 1;
                q.push(p);
                ret++; //FIRST AND ONLY TIME ADDING TO QUEUE
            }

        }
        return ret;

    }
};
