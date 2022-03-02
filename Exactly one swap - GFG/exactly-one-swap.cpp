// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long countStrings(string S)
    {
        // code here
         long long ans = (S.size()*(S.size()-1))/2ll;
       long long a[26] = {0};
       int y=0;
       for(char i : S) a[i-'a']++;
       for(int i=0;i<26;i++){
           if(a[i]>1){
               ans -= (a[i]*(a[i]-1))/2ll;
               y++;
           }
       }
       return y==0?ans:ans+1;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends