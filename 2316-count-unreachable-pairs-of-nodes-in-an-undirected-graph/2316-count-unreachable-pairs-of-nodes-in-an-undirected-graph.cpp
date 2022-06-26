class Solution {
    private:
    vector<vector<int>> graph;
    vector<bool> visit;
    long long count;
public:
    void dfs(int u){
        visit[u] = true;
        count++;
        for(auto v : graph[u]){
            if(!visit[v]){
                dfs(v);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n + 1);
        visit.resize(n + 1, false);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        long long ans = (1ll * n * (n - 1)) / 2;
        for(int i = 1; i <= n; i++){
            count = 0;
            if(!visit[i]) dfs(i);
            
            ans -= (1ll * count * (count - 1)) / 2;
        }
        return ans;
    }
// public:
//     int dfs( vector<vector<int>>&adj, int n){
//         vector<bool>visited(n,0);
        
//     }
    
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         vector<int>adj[];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         dfs(adj,n);
//     }
};