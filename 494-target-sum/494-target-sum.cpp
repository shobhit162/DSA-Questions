class Solution {
public:
    int countofsubsetsum(vector<int>& nums,int d){
        int n=nums.size();
        int dp[n+1][d+1];
         for(int i=0;i<n+1;i++){
        for(int j=0;j<d+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
        // for(int i=0;i<n+1;i++)dp[i][0]=1;
        // for(int j=0;j<d+1;j++)dp[0][j]=0;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<d+1;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][d];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum<abs(target) || (sum+target)%2 != 0)
            return 0;
        int diff=(target+sum)/2;
        return countofsubsetsum(nums,diff);
    }
};