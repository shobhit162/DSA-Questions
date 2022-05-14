// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    int recFunc(int r , int c , vector<vector<int>> &m , vector<vector<int>> &dp){
        // cout << r << " * " << c << endl;
        
        if(r >= m.size()) return 0;
        else if(c < 0 || c >= m[0].size() || m[r][c] == -1) return 0;
        else if(dp[r][c] != -1) return dp[r][c];
        
        int l1 = recFunc(r+1 , c , m , dp);
        int l2 = recFunc(r+1 , c-1 , m , dp);
        int l3 = recFunc(r+1 , c+1 , m , dp);
        dp[r][c] = max(max(l1 , l2) , l3) + m[r][c];
        return dp[r][c];    
    }
    public:
    int MaxGold(vector<vector<int>> &m){
        int r = m.size() , c = m[0].size();
        vector<vector<int>> dp(r , vector<int>(c , -1));
        
        int maxVal = INT_MIN;
        for(int i = 0 ; i < c ; i++){
            maxVal = max(maxVal , recFunc(0 , i , m , dp));
        }
        
        return maxVal;
    }
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends