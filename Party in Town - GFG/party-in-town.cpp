// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int partyHouse(int N, vector<vector<int>> &adj){
        // code here
         int mx=INT_MAX;
      for(int i=1;i<=N;i++){
          vector<int>vis(N+1,0);
          queue<int>q;
          q.push(i);
         vector<int>dis(N+1,0);
          while(q.size()>0){
              int p=q.front();
              q.pop();
              vis[p]=1;
              for(auto &j:adj[p]){
                  if(vis[j]==0){
                      dis[j]=dis[p]+1;
                      q.push(j);
                  }
              }
              
          }
          int mx1=INT_MIN;
          for(int j=1;j<=N;j++){
              mx1=max(mx1,dis[j]);
          }
          mx=min(mx1,mx);
          
      }
      return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, x, y;
        cin>>N;
        vector<vector<int>> adj(N+1);
        for(int i = 0;i < N-1;i++){
            cin>>x>>y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        
        Solution ob;
        cout<<ob.partyHouse(N, adj)<<"\n";
    }
    return 0;
}  // } Driver Code Ends