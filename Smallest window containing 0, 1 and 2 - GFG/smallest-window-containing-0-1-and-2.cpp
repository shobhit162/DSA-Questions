// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
       int a=-1;
       int b=-1;
       int c=-1;
       int res=INT_MAX;
       int n=S.size();
       if(n>=3){
           for(int i=0;i<n;i++){
               if(S[i]=='0') a=i;
               if(S[i]=='1') b=i;
               if(S[i]=='2') c=i;
               if(a!=-1 && b!=-1 && c!=-1){
                   res=min(res,max(a,max(b,c))-min(a,min(b,c))+1);
               }
            }
       }
       return res==INT_MAX ? -1:res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends