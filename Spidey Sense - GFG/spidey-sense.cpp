// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    vector<vector<int>> findDistance(vector<vector<char> >& grid, int m, int n) { 
        
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='B'){
                    ans[i][j]=0;
                    q.push({i,j});
                } 
                else if(grid[i][j]=='W') ans[i][j]=-1;
            }
        }
        
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            
            q.pop();
            
            for(int k=0;k<4;k++){
                int x=i+dx[k]; 
                int y=j+dy[k];
                
                if(x>=0 && x<m && j>=0 && j<n
                    && grid[x][y]=='O'
                    && ans[x][y]>ans[i][j]+1){
                     ans[x][y]=ans[i][j]+1;
                     q.push({x,y});
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ans[i][j]==INT_MAX) ans[i][j]=-1;
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
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends