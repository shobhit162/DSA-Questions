// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  double findSlope(pair<int, int> &p1, pair<int, int> &p2){
        double x1 = p1.first;
        double x2 = p2.first;
        double y1 = p1.second;
        double y2 = p2.second;
        return (y2 - y1)/(x2 - x1);
    }
    int mostBalloons(int N, pair<int, int> arr[]) {
        // Code here
        int ans = INT_MIN;
        for(int i = 0; i < N - 1; i++){
            unordered_map<double, int> mp;
            int cnt = 0;
            for(int j = i + 1; j < N; j++){
                if(arr[i] == arr[j]){
                    cnt++;
                    continue;
                }
                double val = findSlope(arr[i], arr[j]);
                mp[val]++;
            }
            for(auto &e : mp){
                ans = max(ans, e.second + cnt);
            }
        }
        return ans + 1;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends