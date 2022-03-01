// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long countPairs(int N, int X, vector<int> numbers){
        // code here
         unordered_map<string,int>mp;
        long long ans=0;
        for(int i=0;i<N;i++){
            
            string c =to_string(numbers[i]);
            mp[c]++;
        }
        
        string x=to_string(X);
        
        int n=x.length();
        for(int i=0;i<n;i++)
            {
                
                string x1=x.substr(0,i);
                string x2=x.substr(i);
                
                if(mp[x1]>0 and mp[x2]>0)
{
     if(x1!=x2)// IMP IF X IS 764
     ans+=(mp[x1]*mp[x2]);
     else // IF X IS 22
      ans+=mp[x1]*(mp[x1]-1);
}                
                
            }        
    
    return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends