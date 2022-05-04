// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> permute(vector<vector<int>> &arr, int n);


int main() {
    
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr(n);
        
        for(int i=0;i<n;i++)
        {
            int a, b;
            cin>> a>> b;
            arr[i].push_back(a);
            arr[i].push_back(b);
        }
        
        vector<int> ans;
        ans = permute(arr, n);
        for(int i=0;i<n;i++)
            cout << ans[i] << "\n";
        
    }
    
	return 0;
}// } Driver Code Ends


vector<int> permute(vector<vector<int>> &arr, int n)
{
     for(int i = 0; i < n; i++) arr[i].push_back(i + 1);
    sort(arr.begin(), arr.end(), [](auto &a, auto &b){
        int one = a[0] + a[1];
        int two = b[0] + b[1];
        if(one == two) return a[2] < b[2];
        return one < two;
    });
    
    vector<int> ans;
    for(auto it: arr) ans.push_back(it[2]);
    return ans;
    // Complete the function
    
}