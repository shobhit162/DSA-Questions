// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
          set<int>st;
        st.insert(arr[0]);
        vector<int>dp(n , 0);
        dp[n - 1] = arr[n - 1];
        for(int i = n -2 ; i >= 0 ; i--)
        dp[i] = max(arr[i] , dp[i + 1]);
        vector<int>ans;
        long long int maxprod = 1;
        for(int i = 1 ; i < n - 1 ; i++){

            int third = dp[i + 1];
            auto it = st.lower_bound(arr[i]);
            if(it == st.begin()){
                st.insert(arr[i]);
                continue;
            }
            it--;
            int first = *it;
            st.insert(arr[i]);
            if(first < arr[i] && arr[i] < third && first *1LL * arr[i] * 1LL * third >= maxprod){
                maxprod = first *1LL * arr[i] * 1LL * third ;
                ans = {first , arr[i] , third};
            }
        }
        if(ans.empty()){
            ans.push_back(-1);
        }
        return ans;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends