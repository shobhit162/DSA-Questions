// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	     vector<vector<int>> adj(n);
	    for(int i=0; i<edges.size(); i++){
	        adj[edges[i][0]].push_back(edges[i][1]);
	    }
	    queue<int> q;
	    q.push(s);
	    int paths = 0;
	    
	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        if(curr == d){
	            paths++;
	        }
	        for(auto i : adj[curr]){
	            q.push(i);
	            
	        }
	    }
	    return paths;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends