class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,0,sizeof(dp));
        dp[0][1] = 1;
        for(int i=1;i<=obstacleGrid.size();i++){
            for(int j=1;j<=obstacleGrid[0].size();j++){
                if(!obstacleGrid[i-1][j-1])
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};