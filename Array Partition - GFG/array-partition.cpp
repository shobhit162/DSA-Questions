// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

 class Solution{
    public:
    int dp[200005];
    int count[200005];
    bool partitionArray(int N, int K, int M, vector<int> &A){
        memset(dp , -1 , sizeof(dp));
        memset(count , 0 , sizeof(count));
        sort(A.begin(),A.end());
        int n = A.size();
        
        
        for(int i=0; i< N; i++){
            int pos = search(A, i , N , A[i] + M);
            int cnt = (pos -i) + 1;
            count[i] = cnt;
        }
        
        help(0 , N , A , K , M);
        return dp[0];
    }
    
    int search( vector<int> &a , int st ,int en , int tar){
        int res = st;
        while(st <= en){
            int mid = (st+en)/2;
            //cout<<a[mid]<<" "<<tar<<endl;
            if(a[mid] <= tar){
                res = mid;
                st = mid+1;
            } 
            else{
                en = mid-1;
            }
        }
       
        return res;
    }
    
    int help(int idx , int n , vector<int> &a , int k, int m){
        
        if(idx >= n) return 1;
    
        if(dp[idx] != -1) return dp[idx];
        
        
        int cnt = count[idx];
        
        if(cnt < k) {
            
            dp[idx] = 0;
            return 0;
        }
        
        int ans = 0;
        for(int i= idx+k; i<= idx+cnt; i++ ){
          int tem= help(i, n ,a , k , m );
          if(tem == 1){
              ans = 1;
              break;
          }
            
        }
        return dp[idx] = ans;
        
    }
    
    
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends