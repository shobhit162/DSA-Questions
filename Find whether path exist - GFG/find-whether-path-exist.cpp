// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
          queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    // grid[i][j]=0;
                    break;
                }
            }
        }
        while(!q.empty()){
            auto temp=q.front();
            int i=temp.first;
            int j=temp.second;
            
            q.pop();
            if(grid[i][j]==2) return true;
            if(grid[i][j]==0) continue;
            grid[i][j]=0;
            if(i>0)
                q.push({i-1,j});
            if(j>0) 
                q.push({i,j-1});
            if(i<grid.size()-1)    
                q.push({i+1,j});
            if(j<grid[0].size()-1)    
                q.push({i,j+1});
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends