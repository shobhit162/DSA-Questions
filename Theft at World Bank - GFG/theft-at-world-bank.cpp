// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	      multimap<double,long long,greater<double>>mp;
       double r,t;
       int x;
       for (int i=0; i<N; i++) {
           x=t=sqrt(w[i]);
           if (x==t) {
           continue;
           }
           else {
               r=(double)p[i]/w[i];
           mp.insert(pair<double,long long>(r,w[i]));
           }
       }
       long double pro=0.0;
       long long s=C;
       auto i=mp.begin();
       for (; i!=mp.end(); i++) {
           if (i->second>C) {
           break;
           }
           else {
           pro+= (double)((i->first)*(i->second));
           C=C-(i->second);
           }
       }
       if (i!=mp.end()) {
       pro+=(double)(C*i->first);
       }
       return pro;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends