// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long power(long long k,long long m)
   {
       long long ans=1;
       while(m)
       {
           if((m&1)==1)
           {
               ans=(ans*k)%1000000007;
           }
           m=m>>1;
           k=(k*k)%1000000007;
       }
       return ans%1000000007;
   }
    long long karyTree(int k, int m) {
        // code here
         long long b=k;
       long long e=m;
       return power(b,e);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends