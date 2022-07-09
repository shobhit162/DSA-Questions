class Solution {
public:
    
           int twoEggDrop(int n, int k = 2) {
    // int dp[3] = {};
    // int m = 0;
    // while (dp[k] < n) {
    //     ++m;
    //     for (int j = k; j > 0; --j)
    //         dp[j] += dp[j - 1] + 1;
    // }
    // return m;    
               return (int)ceil((-1.+sqrt(1+8*n))/2.);
    }
};