class Solution {
public:
    int uniquePaths(int m, int n) {
        //  vector<vector<int>> dp(m, vector<int>(n, 1));
        // for(int i = 1; i < m; i++)
        //     for(int j = 1; j < n; j++)
        //         dp[i][j] = dp[i-1][j] + dp[i][j-1];   // sum of unique paths ending at adjacent top and left cells
        // return dp[m-1][n-1];         // return unique paths ending at cell (m-1, n-1)
        
           vector<int> dp(n, 1);  // space optimized
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                dp[j] += dp[j-1];   
        return dp[n-1];
    }
};