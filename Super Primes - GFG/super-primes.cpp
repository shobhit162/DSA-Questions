// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    
	    int prime[n+1]={0};
	    unordered_set<int> st;
	    for(int i=2;i<=sqrt(n);i++){
	        if(prime[i] == 0){
	            for(int j=i*i;j<=n;j+=i)
	            prime[j]=1;
	        }
	    }
	    for(int i=2;i<=n;i++){
	        if(prime[i]==0)
	        st.insert(i);
	    }
	    int super=0;
	    for(int i=3;i<=n;i++){
	        if(prime[i]==0){
	            if(st.find(2+i)!=st.end())
	            super++;
	        }
	    }
	    return super;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends