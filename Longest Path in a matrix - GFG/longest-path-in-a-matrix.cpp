// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   bool isValid(int x,int y,int n,int m){
       if(x < 0 || x >= n || y < 0 || y >= m) return (false);
       return (true);
   }
   
   int helper(int x,int y,int n,int m,vector<vector<int>> &mat,vector<vector<int>> &dp){
       if(dp[x][y] != -1) return (dp[x][y]);
       
       int dx[] = {-1,0,1,0};
       int dy[] = {0,1,0,-1};
       
       int mx = 0;
       for(int i = 0; i < 4; i++){
           int nx = x + dx[i];
           int ny = y + dy[i];
           if(isValid(nx,ny,n,m) && mat[nx][ny] > mat[x][y]){
               mx = max(mx,helper(nx,ny,n,m,mat,dp));
           }
       }
       return (dp[x][y] = 1 + mx);
   }
   
   int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n = matrix.size(), m = matrix[0].size();
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
       
       int mx = 1;
       for(int i = 0; i < n; i++){
           for(int j = 0; j < m; j++){
               if(dp[i][j] == -1){
                   mx = max(mx,helper(i,j,n,m,matrix,dp));
               }
           }
       }
       return (mx);
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends