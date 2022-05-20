// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
           int time=0,prev=0,curr=0;
       
       for(int i=0;i<S2.size();i++)
       {
           curr = S1.find(S2[i]);
           time= time+ abs(curr-prev);
           prev = curr;
           curr = 0;
       }
       return time;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends