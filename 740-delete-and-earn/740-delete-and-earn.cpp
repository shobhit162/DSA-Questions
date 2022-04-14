class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=10001;
        vector<int>points(n);
        for(auto i:nums)points[i]+=i;
        int dp[n];
        dp[0]=0;
        dp[1]=points[1];
        for(int i=2;i<n;i++){
            dp[i]=max(points[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};

// vector<int> sum(n, 0);
//     vector<int> dp(n, 0);
    
//     for(auto num: nums){
//         sum[num] += num;
//     }
    
//     dp[0] = 0;
//     dp[1] = sum[1];
//     //now apply the house robbing concept
//     for(int i=2; i<n; i++){
//         dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
//     }
    
//     return dp[n-1];