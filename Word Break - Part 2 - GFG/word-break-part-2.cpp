// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
       int m = s.size();
       vector<vector<string>> dp(m+1);
       dp[0] = {"x"};
       vector<string> ans;
       
       set<string> st;
       for(auto v: dict) st.insert(v);
       
       for(int i=1;i<=m;i++){
           for(int j=i-1;j>=0;j--){
               if(dp[j].size()!=0){
                   string x = s.substr(j,i-j);
                   if(st.find(x)!=st.end()){
                       vector<string> v = dp[j];
                       for(auto k : v){
                           dp[i].push_back(k+" "+x);
                       }
                   }
               }
           }
       }
       for(int i =0;i<dp[m].size();i++){
           dp[m][i] = dp[m][i].substr(2);
       }
       return dp[m];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends