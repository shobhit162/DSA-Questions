// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPrime(long long n){
        if(n==1 || n==0){
            return false;
        }
        if(n==2 || n==3){
            return true;
        }
        if(n%2==0){
            return false;
        }
        
        for(long long i=3;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true; 
    }

    long long primeProduct(long long L, long long R){
        long long prod = 1;
        long long mod = 1e9+7;
        for(long long i=L;i<=R;i++){
            if(isPrime(i)){
                prod*=i;
                prod = prod%mod;
            }
        }
        return prod;    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends