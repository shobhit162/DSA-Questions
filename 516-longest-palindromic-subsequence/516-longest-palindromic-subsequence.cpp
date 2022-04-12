class Solution {
public:
    int dp[1001][1001];
    int LCS(string s, string b){
        int n=s.size();
        int m=b.size();
        for(int i=0;i<n+1;i++)dp[i][0]=0;
        for(int j=0;j<m+1;j++)dp[0][j]=0;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string b=string(s.rbegin(),s.rend());
          
        return LCS(s,b);
    }
};