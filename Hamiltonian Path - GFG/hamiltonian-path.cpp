//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
      bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> path , vis(N+1, 0) , adj[N+1];
        for(int i=0; i< M; i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        for(int i=0; i< N; i++){
            if(!vis[i]){
                if(dfs(i , N , adj , path , vis)) return 1;
            }
        }
        return 0;
        
    }
    
    bool dfs(int node ,int n, vector<int> adj[] , vector<int> &path, vector<int> &vis){
        path.push_back(node);
        vis[node] = 1;
        if(path.size() == n) return 1;
        
        for(int x: adj[node]){
            if(!vis[x]){
                if(dfs(x, n , adj , path , vis)) return 1;
            }
        }
        path.pop_back();
        vis[node] = 0;
        return 0;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends