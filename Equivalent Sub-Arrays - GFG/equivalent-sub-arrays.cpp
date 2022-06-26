// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int a[], int n)
    {
        //code here.
        unordered_set<int> myset;
        for(int i=0; i<n; i++) myset.insert(a[i]);
        
        unordered_map<int, int> m;
        int cnt = myset.size(), i = 0, j = 0, res = 0;
        
        while(j<n) {
            m[a[j]]++;
            while(i<=j and m.size()==cnt) {
                res += n-j;
                m[a[i]]--;
                if(m[a[i]]==0) {
                    m.erase(a[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends