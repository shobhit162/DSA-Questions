// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPrime(int num){
        if(num==1){
            return false;
        }
        if(num==2 || num==3){
            return true;
        }
        if(num%2==0){
            return false;
        }
        for(int i=3;i<=sqrt(num);i+=2){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    
    vector<int> primeDivision(int N){
        //Checking for base cases
        if(N==3){
            vector<int> ans{1,3};
            return ans;
        }
        if(isPrime(N-2)){
            vector<int> ans{2,N-2};
            return ans;
        }
        
//Just iterate from 3 to N-1 and check if N-i 		             is also prime
//If it is prime than that is our answer

        vector<int> ans;
        for(int i = 3;i < N ;i+= 2){
//Check if i is prime       
            if(isPrime(i)){     
                int dif = (N-i);
// Check if N-i is prime                
                if(isPrime(dif)){ 
                    ans.push_back(i);
                    ans.push_back(dif);
                    break;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends