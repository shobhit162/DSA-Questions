class Solution {
public:
     void dfs(int p, vector<int> &vis, vector<vector< int>> &adj, int dist)
        {
            vis[p] = dist;
            for (auto x: adj[p])
            {
                if (vis[x] == -1)
                {
                    dfs(x, vis, adj, dist + 1);
                }
            }
        }
    int closestMeetingNode(vector<int> &e, int node1, int node2)
    {
        int n = e.size();
        vector<int> vis1(n, -1), vis2(n, -1);
        vector<vector < int>> adj(n);
        int i=0;
        for (auto x: e)
        {
            if(x!=-1)
            adj[i].push_back(x);
            i++;
        }
        dfs(node1, vis1, adj, 0);      
        dfs(node2, vis2, adj, 0);    
        
        int ans=-1, mini=INT_MAX; 
        for (int i = 0; i < n; i++)
        {          
           if(vis1[i]>=0 && vis2[i]>=0)
           {  int a = max(vis1[i], vis2[i]);
               if(a<mini)
               {
                   mini = a;
                   ans = i;
               }
           }
        }
        
        return ans;
    }
};