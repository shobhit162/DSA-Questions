// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
   int fun(int n, int k, int x, vector<int>&arr, vector<vector<int>> &dp) {
    if(n == 0) return x == k;
    if(dp[n][x] != -1) return dp[n][x];
    return dp[n][x] = fun(n-1, k, (x^arr[n-1]), arr, dp) + fun(n-1, k, x, arr, dp);
}
int subsetXOR(vector<int> arr, int N, int K) {
    vector<vector<int>> dp(N+1, vector<int>(128, -1));
    return fun(N, K, 0, arr, dp);
}
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends