// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
 
	public:
	int numberOfCells(int n, int m, int r, int c, int u, int d, vector<vector<char>> &mat)
	{
		// Your code goes here
		if(mat[r][c]=='#') return 0;
		 int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
 vector<vector<bool>> vis(n+1,vector<bool>(m+1,false));
 queue<vector<int>> q;
 q.push({r,c,0,0});
 int ans = 0;
 while(!q.empty()){
     vector<int> curr = q.front();
     ans++;
     vis[curr[0]][curr[1]]= true;
     q.pop();
     for(int i=0; i<4; i++){
         int x = curr[0]+dx[i];
         int y = curr[1]+dy[i];
         int up = curr[2];
         int down = curr[3];
         if(x>=0 && x<n && y>=0 && y<m && mat[x][y]=='.' && !vis[x][y]){
             if(up == u && dx[i] == -1 || down == d && dx[i] == 1) continue;
             
             vis[x][y] = true;
             q.push({x,y,up+(dx[i]==-1), down+(dx[i]==1)});
         }
     }
 }
 return ans;
	}

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;

    while (t--)
    {
    	int n, m, r, c, u, d;
        cin >> n >> m >> r >> c >> u >> d;
        
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < m; j++)
        	{
        		cin >> mat[i][j];
        	}
        }

      

        Solution obj;
        cout << obj.numberOfCells(n, m, r, c, u, d, mat) << "\n";
    
    }

    return 0;
}


  // } Driver Code Ends