class Solution {
public:
    // int numRollsToTarget(int d, int f, int target) {
    //  int m=1000000007;
    //     vector<vector<int> > dp(d+1, vector<int>(target+1, 0));
    //     dp[0][0]=1;
    //     for(int i=1; i<=d; i++){
    //         for(int j=1; j<=target; j++){
    //             for(int k=1; k<=f; k++){
    //                 if(k<=j)
    //                     dp[i][j]=((dp[i][j]%m)+(dp[i-1][j-k]%m))%m;
    //             }
    //         }
    //     }
    //     return dp[d][target];    
    // }
     #define MOD 1000000007
    int dp[32][1002];
    
    int solve(int d, int f, int target){
        if(d==0 && target==0) return 1;
        if(d<=0 || target<=0) return 0;
        if(dp[d][target] != -1) return dp[d][target];
     
        int sum=0;
        for(int i=1;i<=f;i++){
            sum = (sum % MOD + solve(d-1,f,target-i)%MOD)%MOD;
        }
        dp[d][target] = sum;
        return dp[d][target];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(d,f,target);
    }
};