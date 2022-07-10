// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> ans;
void paths(int i, int j, int n, int m, vector<vector<int>> &grid, vector<int>& arr){
    arr.push_back(grid[i][j]);
    if(i+1 < n)    
        paths(i+1,j,n,m,grid,arr);
    if(j+1 < m)    
        paths(i,j+1,n,m,grid,arr);
    if(i==n-1 && j==m-1)
        ans.push_back(arr);
    arr.pop_back();
}
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<int> arr;
        paths(0,0,n,m,grid,arr);
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends