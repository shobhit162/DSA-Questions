class Solution {
public:
    void dfs(vector<vector<char>>& matrix,int i,int j, int row, int col){
        if(i<0 || i>=row || j<0 || j>=col || matrix[i][j]!='1')
            return;
        matrix[i][j]='2'; // mark current as visited
        dfs(matrix,i+1,j,row,col); //down
        dfs(matrix,i,j+1,row,col); //right
        dfs(matrix,i-1,j,row,col); //top
        dfs(matrix,i,j-1,row,col);  //left
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if(row==0)
            return 0;
        int col=grid[0].size();
        int no_of_island=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,row,col);
                    no_of_island++;
                }
            }
        }
        return no_of_island;
    }
};