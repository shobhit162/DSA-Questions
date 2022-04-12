class Solution {
public:
    int dp[1001][1001];
    int LCS(string& X, string& Y, int n, int m){
        if(n==0||m==0)return 0;
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(X[n-1]==Y[m-1])
            return dp[n][m]= 1+LCS(X, Y, n-1,m-1);
        else 
            return dp[n][m]= max(LCS(X,Y,n,m-1),LCS(X,Y,n-1,m));

    }
    int longestCommonSubsequence(string text1, string text2) {
        //recursion  approach but tle  ,now memoization 
        int n=text1.size();
        int m=text2.size();
        
        memset(dp,-1,sizeof(dp));
        if(n==0 ||m==0)return 0;
//         for(int i=0;i<n+1;i++)dp[i][0]=0;
//         for(int j=0;j<m+1;j++)dp[0][j]=0;
                
        // for(int i=1;i<n+1;i++)
        //     for(int j=1;j<m+1;j++){
        if(text1[n-1]==text2[m-1])
               return dp[n][m]= 1+LCS(text1,text2,n-1,m-1);
        else 
                return dp[n][m]= max(LCS(text1,text2,n,m-1),LCS(text1,text2,n-1,m));
        //     }
        // return dp[n][m];
    }
};