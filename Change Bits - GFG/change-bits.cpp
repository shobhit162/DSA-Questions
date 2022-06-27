// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
         if(N == 0) return {-1,-1};
        
        int m = N;
        int mask = 0;
        
        while(m) {
            mask = ((mask<<1)|1);
            m = m>>1;
        }
        
        int a = (N|mask);
        int b = abs(a-N);
        
        return {b,a};
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends