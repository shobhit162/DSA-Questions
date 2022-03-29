class Solution {
public:
    int dp[601][101][101];
    int dpfun(int sz,int m,int n,vector<string>& vt){
        if(dp[sz][m][n]!=-1)return dp[sz][m][n];
        if(sz==0 || (m==0 && n==0)) return dp[sz][m][n]=0;
        string s=vt[sz-1];
        int a=0;
        int b=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') a++;
            else b++;
        }
        if(m-a>=0 && n-b>=0){
            return dp[sz][m][n]=max(1+dpfun(sz-1,m-a,n-b,vt),dpfun(sz-1,m,n,vt));
        }
        else return dp[sz][m][n]=dpfun(sz-1,m,n,vt);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        memset(dp,-1,sizeof(dp));
        return dpfun(sz,m,n,strs);
    }
};