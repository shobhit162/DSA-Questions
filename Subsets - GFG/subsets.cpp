// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
         vector<vector<int>>ans;
       ans.push_back(vector<int> ());
       for(int num : A)
       {
           int n=ans.size();
           for(int i=0 ;i<n;i++)
           {
               vector<int> temp (ans[i]);
               temp.push_back(num);
               ans.push_back(temp);
           }
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends