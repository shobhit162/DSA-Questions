// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[101][101];
   int sum(int i,int j,int frq[]){
       int s=0;
       for(int k=i;k<=j;k++){
           s+=frq[k];
       }
       return s;
   }
   int mcm(int i,int j,int freq[]){
      
       if(j<i) return 0;
       if(i==j) return freq[i];
       if(dp[i][j]!=-1) return dp[i][j];
       int sum1=sum(i,j,freq);
       int ans=INT_MAX;
       for(int k=i;k<=j;k++){
           ans=min(ans,mcm(i,k-1,freq)+mcm(k+1,j,freq));
       }
       return dp[i][j]=ans+sum1;
   }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        memset(dp,-1,sizeof dp);
      return mcm(0,n-1,freq);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends